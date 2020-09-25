/**
 * @Author: Nick Steele <nichlock>
 * @Date:   18:41 Sep 13 2020
 * @Last modified by:   Nick Steele
 * @Last modified time: 21:35 Sep 24 2020
 */

/**
 * This code will open an image and show it, allowing you to change a value while it runs using a
 * trackbar.
 *
 * It will usually try to open default_test_image, but if you name an image in the command, it will
 * load that instead.
 * Ex: `rosrun template-opencv template-opencv images/image.jpg` <-- end part
 */

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const std::string default_test_image = "/images/sample_image.jpg";

bool loadImage(int, char const *[], Mat &);

void update_hue(int, void *);

Mat image_in; // Original image
Mat image_hsv; // Converted color image
Mat image_hsv_modified; // For display

std::string window_image = "Image";

bool trackbarsChanged = true; // For OpenCV trackbar usage

int trackbar_hue_value = 0; // Ammount to ad to the hue (aka color) is decided by the trackbar
std::string trackbar_hue_name = "Hue";

int main(int argc, char const *argv[]) {
  // EXIT_FAILURE indicates to the OS that this program failed, which can be
  // useful for when we run a bunch of programs.
  if (!loadImage(argc, argv, image_in)) return EXIT_FAILURE;

  // Resize the image to a more view-able size on my screen
  resize(image_in, image_in, Size(500, 500), 0, 0, INTER_AREA);
  cvtColor(image_in, image_hsv, COLOR_BGR2HSV); // Convert to the more useful HSV color space

  namedWindow(window_image); // Create the window for the trackbar

  createTrackbar(trackbar_hue_name, // Bar name
                 window_image, // Window to put bar on
                 &trackbar_hue_value, // This will be filled with the trackbar value automatically
                 255, // Maximum value
                 update_hue); // Callback function is run when the trackbar is updated.

  setTrackbarMax(trackbar_hue_name, // Bar name
                 window_image, // Window
                 255); // Maxvalue
  setTrackbarMin(trackbar_hue_name, // Bar name
                 window_image, // Window
                 0); // Minvalue

  /*
   ********* Mind-blowing algoriths and code go here
   */

  while (true) {
    waitKey(1);
    // Wait for trackbar changes, only update when they are changed.
    // Trackbars are an openCV feature which can change a variable value while
    // the program is running.
    if (!trackbarsChanged) { continue;}
    trackbarsChanged = false;

    /*
     *
     ********* Mind-blowing algoriths and code (that use the trackbars) go here
     *
     */

    // Example of something updated by trackbar.
    image_hsv_modified = image_hsv + trackbar_hue_value;

    // To display a color image, make sure to have it in BGR colors!
    cvtColor(image_hsv_modified, image_hsv_modified, COLOR_HSV2BGR);
    // Show results. Add as many as you need! This is what opens the window
    imshow(window_image, image_hsv_modified); // see waitKey(1) line below!

    // MUST BE HERE for images to actually show.
    waitKey(1);
  }

  return EXIT_SUCCESS;
} // main

void update_hue(int, void *) {
  // This can be run thousands of times, instantly, on a single change on the trackbar.
  // That means that it is important to not overwrite the image here, since that
  // would take forever. This gets the main() funtion to update it seperately.
  trackbarsChanged = true;
} // update_hue

/** Automatically loads OpenCV image given as command-line argument, or load
 * default_test_image if none provided.
 *
 * @param image The image to be filled
 * @return false if the image was not loaded
 */
bool loadImage(int argc, char const *argv[], Mat &image) {
  if (argc > 1) {
    cout << "Loading image: " << argv[1] << "\n";
    image = imread(argv[1]);
  } else {
    cout << "No image argument given. Loading default image " <<
      default_test_image << "\n";
    image = imread(default_test_image);
  }
  if (image_in.empty()) {
    cout << "Empty input image!\n";
    return false;
  }
  return true;
} // loadImage
