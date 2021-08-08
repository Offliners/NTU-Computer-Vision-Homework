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

    // binarize
    Mat img1;
    threshold(img, img1, 127, 255, 0);
    imwrite("demo/binarize.png", img1);
    cout << "Downloaded binarize image" << endl;

    // histogram
    Mat hist;
    int histSize = 256;
    float range[] = {0, 255};
    const float* histRange = {range};
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange);
    Mat img2(256, 256, CV_8UC1, Scalar(255));
    float histmax = *max_element(hist.begin<float>(), hist.end<float>());
    for(int i = 0; i < 256; ++i)
    {
        int intensity = static_cast<int>(hist.at<float>(i) * 0.9 * 256 / histmax);
        line(img2, Point(i, 255), Point(i, 255 - intensity), Scalar(0));
    }
    imwrite("demo/histogram.png", img2);
    cout << "Downloaded histogram image" << endl;

    // connected components
    Mat labels, stats, centroids, img3;
    cvtColor(img1, img3, COLOR_GRAY2RGB);
    connectedComponentsWithStats(img1, labels, stats, centroids, 8);
    for(int i = 0; i < stats.rows; ++i)
    {
        int x = stats.at<int>(Point(0, i));
        int y = stats.at<int>(Point(1, i));
        int width = stats.at<int>(Point(2, i));
        int height = stats.at<int>(Point(3, i));
        int area = stats.at<int>(Point(4, i));

        if(area < 500 || area > 120000)
            continue;

        drawMarker(img3, Point(x + width / 2, y + height / 2), Scalar(0, 0, 255), MARKER_CROSS, 20, 2);
        rectangle(img3, Rect(x, y, width, height), Scalar(255, 0, 0), 3);
    }

    imwrite("demo/connected-components.png", img3);
    cout << "Downloaded connected-components image" << endl;

    return 0;
}