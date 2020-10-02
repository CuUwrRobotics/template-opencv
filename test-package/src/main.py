#!/usr/bin/env python

# @Author: Nick Steele
# @Date:   19:13 Oct 01 2020
# @Last modified by:   Nick Steele
# @Last modified time: 20:38 Oct 01 2020

# This code will open an image and show it, allowing you to change a value while it runs using a
# trackbar.
#
# It will usually try to open default_test_image, but if you name an image in the command, it will
# load that instead.
# Ex: `rosrun template-opencv main.py images/image.jpg` <-- end part

import cv2
import sys
import numpy as np

default_test_image = "/images/sample_image.jpg"

# OpenCV tracks windows and trackbars using titles
window_image_title = "Image"

# Ammount to add to the hue (aka color) is decided by the trackbar
hue_trackbar_value = 0
hue_trackbar_name = "Hue"

trackbar_changed = True  # Flag for when a trackbar is updated


def hue_trackbar(val):
    """Trackbar callback that sets hue and raises update flag"""
    # Technically, the advice is to create you image in these callbacks.
    # Sometimes, though, OpenCV will call these thousands of times even though
    # the trackbar was only moved one unit. That would freeze up any computer,
    # so we just set a value and raise a flag that is checked in the while(True)
    # loop
    global trackbar_changed
    global hue_trackbar_value
    trackbar_changed = True   # Set flag so the image is updated
    hue_trackbar_value = val  # Set value that will be used to update the image


def loadImage(args):
    """Loads an image from the first argument in the calling function.
    If non provided, loads default image. Exits program if image wasn't there."""
    if(len(args) < 2):
        print("No image argument given. Loading default image " + default_test_image)
        image = cv2.imread(default_test_image)
        if(image.size == 0):
            print("Empty or no image provided. Cannot open.")
            sys.exit(2)
        return image
    print("Loading image: " + args[1])
    image = cv2.imread(default_test_image)
    if(image.size == 0):
        print("Empty or no image provided. Cannot open.")
        sys.exit(2)
    return image


if __name__ == '__main__':
    image_in = loadImage(sys.argv)  # Load image

    # Resize the image to a more view-able size on my screen
    image_in = cv2.resize(image_in, (500, 500), cv2.INTER_AREA)
    # Convert to the more useful HSV color space
    image_hsv = cv2.cvtColor(image_in, cv2.COLOR_BGR2HSV)

    # Create the window for the trackbar and image to bee put in
    cv2.namedWindow(window_image_title)
    cv2.createTrackbar(hue_trackbar_name,   # Bar name
                       window_image_title,  # Window to put bar on
                       hue_trackbar_value,  # Minvalue/default to start trackbar on
                       255,                 # Maxvalue for trackabr
                       hue_trackbar)        # Callback function is called every time the trackabr changes

    #
    # Mind-blowing algorithms and code go here
    #

    while(True):
        cv2.waitKey(1)
        if trackbar_changed is False:
            continue
        trackbar_changed = False

        #
        # Mind-blowing algorithms and code (that use the trackbars) go here
        #

        # Example code will simply add trackbar value to the image hue
        image_hsv_modified = cv2.add(image_hsv, np.full(
            (500, 500, 3), (hue_trackbar_value, 0, 0), np.uint8))

        # Show our work
        # Need to convert the image before viewing!
        image_hsv_modified = cv2.cvtColor(
            image_hsv_modified, cv2.COLOR_HSV2BGR)
        cv2.imshow(window_image_title, image_hsv_modified)
        # MUST BE HERE for images to actually show.
        cv2.waitKey(1)
