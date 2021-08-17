# Homework 3 - Histogram Equalization
### Origin Iamge
![Origin Iamge](data/lena.bmp)

### Usage
```
cd hw3
mkdir build && cd build
cmake ..
make
cd ..
./build/hw3 data/lena.bmp
```
All generated images are saved in `demo`

## Description
Write a program to generate images and histograms:

(a) original image and its histogram

|Image|histogram|
|-|-|
|![origin](demo/origin.png)|![histogram](demo/origin_histogram.png)|

(b) image with intensity divided by 3 and its histogram

|Image|histogram|
|-|-|
|![origin_divide_3](demo/origin_divide_3.png)|![histogram_divide_3](demo/origin_divide_3_histogram.png)|

(c) image after applying histogram equalization to (b) and its histogram

|Image|histogram|
|-|-|
|![histogram_equalization](demo/histogram_equalization.png)|![histogram_equalization_histogram](demo/histogram_equalization_histogram.png)|