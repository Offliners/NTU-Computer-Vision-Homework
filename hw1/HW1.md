# Homework 1 - Basic Image Manipulation
### Origin Iamge
![Origin Iamge](data/lena.bmp)

### Usage
```
cd hw1
mkdir build && cd build
cmake ..
make
cd ..
./build/hw1 data/lena.bmp
```
All generated images are saved in `demo`

## Description
### Part 1
Write a program to do the following requirement.

(a) upside-down lena.bmp

![upside-down](demo/upside-down.png)
    
(b) right-side-left lena.bmp

![right-side-left](demo/right-side-left.png)
    
(c) diagonally flip lena.bmp

![diagonally-flip](demo/diagonally-flip.png)

### Part 2 
Write a program or use software to do the following requirement.
    
(d) rotate lena.bmp 45 degrees clockwise

![rotate-45](demo/rotate-45.png)

(e) shrink lena.bmp in half

![shrink](demo/shrink.png)

(f) binarize lena.bmp at 128 to get a binary image

![binarize](demo/binarize.png)