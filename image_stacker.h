/**
 * @file image_stacker.h
 * @author Mason Enochs
 * @date 2025-03-04
 * @brief Class definition for the image stacker, its private contents, and its operations
 * 
 * The image stacker class will take in a .ppm file, or multiple, to display an image with the average color values of each pixel. 
 */

#ifndef IMAGE_STACKER_H
#define IMAGE_STACKER_H

#include <string>
#include <vector>

using namespace std;


/**
 * This class will define an image stacker object whos job is to take in image data from a .ppm text/image file (or multiple) in order to display another image with the averaged values of each pixel im order to create a new image entirely.
 *
 * @class Stacker image_stacker.h "ImageStacker/image_stacker.h"
 * @brief defines the image stacker class
 *
 */
class Stacker
{
 private:
  string magicNumber;  // The P3 value
  int width, height, maxColor;  // The width, height, and maximum color value for the image

  // A struct containing three integers: red, green, and blue
  struct Pixel
  {
    int red, green, blue;  // RGB values for a pixel
  };

  vector<Pixel> pixels;  // A vector of pixel structs storing color information for the stacked image

 public:
      Stacker();  // Constructor to initialize the Stacker object
      ~Stacker();  // Destructor

/**
 * Reads in image data from a .ppm file
 *
 * @param string fName 
 * @pre 
 * @return void 
 * @post 
 * 
 */
      void readIn(string fName);

/**
 * saves the image data to a new file
 *
 * @param string fName 
 * @pre 
 * @return void 
 * @post 
 * 
 */
      void saveToFile(string fName) const;

/**
 * displays the image data 
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
      void display();

 /**
 * stacks images together and returns a new stacker object containing the new image
 *
 * @param const vector<Stacker>& images 
 * @pre 
 * @return static 
 * @post 
 * 
 */
      static Stacker stackImages(const vector<Stacker>& images);
};
