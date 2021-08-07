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

	return 0;
}