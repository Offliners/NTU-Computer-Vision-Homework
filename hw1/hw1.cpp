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

    // upside-down
    Mat img1;
    flip(img, img1, 0);
    imwrite("demo/upside-down.png", img1);
    cout << "Downloaded upside-down image" << endl;

    // right-side-left
    Mat img2;
    flip(img, img2, 1);
    imwrite("demo/right-side-left.png", img2);
    cout << "Downloaded right-side-left image" << endl;

    // diagonally flip
    Mat img3;
    transpose(img, img3);
    imwrite("demo/diagonally-flip.png", img3);
    cout << "Downloaded diagonally-flip image" << endl;

    // rotate 45 degrees
    Mat img4;
    Point2f pt(img.cols/2., img.rows/2.);
    Mat r = getRotationMatrix2D(pt, -45, 1.0);
    warpAffine(img, img4, r, Size(img.cols, img.rows));
    imwrite("demo/rotate-45.png", img4);
    cout << "Downloaded rotate-45 image" << endl;

    // shrink
    Mat img5;
    resize(img, img5, Size(img.cols/2., img.rows/2.), INTER_LINEAR);
    imwrite("demo/shrink.png", img5);
    cout << "Downloaded shrink image" << endl;

    // binarize
    Mat img6;
    threshold(img, img6, 127, 255, 0);
    imwrite("demo/binarize.png", img6);
    cout << "Downloaded binarize image" << endl;

    return 0;
}