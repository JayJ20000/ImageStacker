#include "image_stacker.h"
#include <iostream>
#include <vector>

using namespace std;

string imageIncramenter(int i);

int main()
{
  int numImages;           // Number of images to stack
  string fileName;         // Variable to store file name
  vector<Stacker> images;  // Vector to store the images

  // Ask for the number of images
  cout << "Enter the number of images to stack: ";
  cin >> numImages;

  // Checking user input
  if (numImages <= 0)
    {
      cerr << "Err: Incorrect number of images." << endl;
      return 1;
    }

  cout << "Please enter the name of the image: ";
  cin >> fileName;
  cout << endl;
  
  // Read in multiple images based on input
  for (int i = 0; i < numImages; ++i)
    {
      
      Stacker img;       // Create a Stacker object for the image
      img.readIn(fileName + "/" + fileName + imageIncramenter(i));  // Read in the image from the file
      images.push_back(img); // Store the image in the vector
    }

  // Stack the images
  Stacker stackedImage = Stacker::stackImages(images);

  // Save the resulting stacked image to a new file
  stackedImage.saveToFile("stacked_images.ppm");

  return 0;
}

string imageIncramenter(int i)
{
  string end = ".ppm";
  i++;
  if(i < 10)
    {
      return "_00" + to_string(i) + end;
    }
  else if(i < 100)
    {
      return "_0" + to_string(i) + end;
    }
  else
    {
      return "_" + to_string(i) + end;
    }
}
