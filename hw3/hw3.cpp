#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

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

    // histogram
    Mat hist;
    int histSize = 256;
    float range[] = {0, 255};
    const float* histRange = {range};
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange);
    Mat img1(256, 256, CV_8UC1, Scalar(255));
    float histmax = *max_element(hist.begin<float>(), hist.end<float>());
    for(int i = 0; i < 256; ++i)
    {
        int intensity = static_cast<int>(hist.at<float>(i) * 0.9 * 256 / histmax);
        line(img1, Point(i, 255), Point(i, 255 - intensity), Scalar(0));
    }
    imwrite("demo/histogram.png", img1);
    cout << "Downloaded histogram image" << endl;

    return 0;
}