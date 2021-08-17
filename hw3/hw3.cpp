#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

void calHistandDownload(Mat, string);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        cout << "Error usage!" << endl;
        return 1;
    }

    string img_path = argv[1];
    Mat img = imread(img_path, IMREAD_GRAYSCALE);
    if(img.empty())
    {
        cout << "Could not read the image: " << img_path << endl;
        return 1;
    }

    // Origin
    string origin = "origin";
    calHistandDownload(img, origin);

    // divided by 3
    Mat img1(img / 3.);
    string divide_3 = "origin_divide_3";
    calHistandDownload(img1, divide_3);

    // histogram equalization
    Mat img2(img.size(), CV_8UC1);
    equalizeHist(img1, img2);
    string histogram_equalization = "histogram_equalization";
    calHistandDownload(img2, histogram_equalization);

    return 0;
}

void calHistandDownload(Mat image, string file_name)
{
    imwrite("demo/" + file_name + ".png", image);
    cout << "Downloaded " + file_name + " image" << endl;

    Mat hist;
    int histSize = 256;
    float range[] = {0, 255};
    const float* histRange = {range};
    calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, &histRange);
    Mat temp(256, 256, CV_8UC1, Scalar(255));
    float histmax = *max_element(hist.begin<float>(), hist.end<float>());
    for(int i = 0; i < 256; ++i)
    {
        int intensity = static_cast<int>(hist.at<float>(i) * 0.9 * 256 / histmax);
        line(temp, Point(i, 255), Point(i, 255 - intensity), Scalar(0));
    }
    imwrite("demo/" + file_name + "_histogram.png", temp);
    cout << "Downloaded " + file_name + " histogram image" << endl;
}