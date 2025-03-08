#include "image_stacker.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Stacker::Stacker() : width(0), height(0), maxColor(0) {}  // Default constructor initializing values to 0

Stacker::~Stacker() {}  // Destructor

void Stacker::readIn(string fName)
{
  ifstream file(fName);  // Open the file

  if (!file)  // Check if the file could not be opened
    {
      cerr << "Err: Could not open file " << fName << endl;  // Error message
      return;  // Exit the function if the file can't be opened
    }

  // Read the magic number dimensions, and max color value
  file >> magicNumber >> width >> height >> maxColor;

  if (magicNumber != "P3")  // Check if the file format is "P3"
    {
      cerr << "Err: Wrong file format " << endl;  // Output an error message
      return;
    }

  // Reserve space in the vector for the number of pixels
  pixels.reserve(width * height);

  // Read each pixel's RGB values and add them to the vector
  for (int i = 0; i < width * height; ++i)
    {
      Pixel pixel;  // Object to hold RGB values
      file >> pixel.red >> pixel.green >> pixel.blue;  // Read values from the file
      pixels.push_back(pixel);  // Add the pixel to the vector
    }

  file.close();  // Close
}

void Stacker::saveToFile(string fName) const
{
  ofstream file(fName);  // Open the file for writing

  if (!file)  // Check the file could not be opened
    {
      cerr << "Err: Could not create file " << fName << endl;
      return;  // Exit the function if the file can't be opened
    }

  // Write the image magic number, width, height, max color value to the file
  file << magicNumber << "\n" << width << " " << height << "\n" << maxColor << "\n";

  // Loop through the pixels vector and write each values to the file
  for (size_t i = 0; i < pixels.size(); ++i)
    {
      const Pixel& pixel = pixels[i];  // Get the pixel reference

      file << pixel.red << " " << pixel.green << " " << pixel.blue << " ";  // Write RGB values to the file
    }

  file.close();  // Close the file after writing
  cout << "Stacked image saved as " << fName << endl;
}

Stacker Stacker::stackImages(const vector<Stacker>& images)
{
  if (images.empty())  // Check if the vector is empty
    {
      cerr << "Err: No images for stacking." << endl;
      return Stacker();  // Return an empty object
    }

  // Initialize the image properties
  int width = images[0].width;
  int height = images[0].height;
  int maxColor = images[0].maxColor;
  string magicNumber = images[0].magicNumber;

  // Check if all images have the same dimensions and format
  for (size_t i = 0; i < images.size(); ++i)
    {
      const Stacker& img = images[i];  // Reference to the current image

      if (img.width != width || img.height != height || img.magicNumber != magicNumber)
	{
	  cerr << "Err: Images must have the same dimensions." << endl;  // If images don't match
	  return Stacker();  // Return an empty Stacker object
	}
    }

  // Create a new Stacker object to store the stacked image
  Stacker stackedImage;
  stackedImage.width = width;  // Set the width to the first image's width
  stackedImage.height = height;  // Set the height to the first image's height
  stackedImage.maxColor = maxColor;  // Set the max color value to the first image's max color value
  stackedImage.magicNumber = magicNumber;  // Set the magic number to the first image's magic number
  stackedImage.pixels.resize(width * height);  // Resize the pixels vector to hold all pixels

  // Loop through each pixel position
  for (int i = 0; i < width * height; ++i)
    {
      int sumRed = 0, sumGreen = 0, sumBlue = 0;  // Initialize the sum for each color

      // Loop through each image and add up the values
      for (size_t j = 0; j < images.size(); ++j)
	{
	  const Stacker& img = images[j];  // Reference to the current image

	  sumRed += img.pixels[i].red;  // Add the red pixel
	  sumGreen += img.pixels[i].green;  // Add the green pixel
	  sumBlue += img.pixels[i].blue;  // Add the blue  pixel
	}

      // Calculate the average RGB value for the pixel and store it in the stacked image
      stackedImage.pixels[i].red = sumRed / images.size();
      stackedImage.pixels[i].green = sumGreen / images.size();
      stackedImage.pixels[i].blue = sumBlue / images.size();
    }

  return stackedImage;  // Return the stacked image
}

void Stacker::display()
{
  // Output the magic number, width, height, and max color
  cout << magicNumber << "\n" << width << " " << height << "\n" << maxColor << "\n";

  // Loop through the pixels vector and output each pixel's RGB values
  for (size_t i = 0; i < pixels.size(); ++i)
    {
      const Pixel& pixel = pixels[i];

      // Output the RGB values of the pixel
      cout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
    }

  cout << endl;
}
