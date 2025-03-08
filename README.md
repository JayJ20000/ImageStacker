# ImageStacker
## Overview 
- This program takes multiple PPM images and stacks them by averaging the pixel values. The stacked image will be saved as stacked_output.ppm.

## How it works
- The program asks the user to enter the number of images to stack.
- User then enters the filenames of the images to stack.
- The program reads each image file
- Then stacks the images by averaging their values
- The stacked image is then saved to stacked_output.ppm

## How to Run
-  g++ -o image_stacker main.cpp ImageStacker.cpp
-  Run make with the implemented Makefile
-  Run the program with ./image_stacker

## Challenges
- Making sure the each image's pixels's red, green, and blue values were correctly averaged.
- Triple checking loop indexes making sure the pixel's data was read correctly.
- Making sure the images had matching dimensions and format. Gave a few problems.
- Processing and storing image data

## Division of labor -
- We decided that Mason would do the header file, Makefile, and README.md file while Jalen would do the implementation, main.cpp, and image.cpp files. 
