#include<iostream>
#include<cmath>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

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
    Mat img = imread(img_path, IMREAD_COLOR);
    if(img.empty())
    {
        cout << "Could not read the image: " << img_path << endl;
        return 1;
    }

    // Original Image
    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    imshow("Original Image", img);

    Mat img2;
    flip(img, img2, 0);
    namedWindow("upside-down", CV_WINDOW_AUTOSIZE);
    imwrite("demo/upside-down.png", img2);
    cout << "Downloaded upside-down image" << endl;

	return 0;
}