<!--
@Author: Nick Steele
@Date:   20:39 Sep 24 2020
@Last modified by:   Nick Steele
@Last modified time: 20:45 Sep 24 2020
-->

# HOW TO SET UP THIS TEMPLATE

-   [ ] Click 'Use this template' and create your repository (check our [workflow information](https://github.com/CuUwrRobotics/workflow) for more on naming repositories first!)
-   [ ] Run the code from file setup/labels.json in Chrome's Inspect Element console while on the GitHub [labels](../../labels) page to update all labels
-   [ ] If the submodules are not included (if you can't see the folders `ros-docker` and `catkin-setups`), run these commands from your console in the repository:
    -   [ ] `git submodule add https://github.com/CuUwrRobotics/ros-docker.git`
    -   [ ] `git submodule add https://github.com/CuUwrRobotics/catkin-setups.git`
-   [ ] Delete `setup/*` directory and files
-   [ ] Update this readme with a description of your program and any particulars of using it

# HOW TO USE THIS TEMPLATE

-   `cd ros-docker`
-   `make`
-   Once it finishes making the docker container, detach (`^P` then `^Q` where `^` means `ctrl-`)
-   `docker exec -it piranhabot_container bash`
-   `cd ~/catkin_make`
-   `make`
-   `rosrun template-opencv template-opencv`
-   An image should show up! (Make sure MobaXterm is running.)

This has the code to run a program that will open an image, load it, modify it, and go from there. I highly recommend using the existing code as the starting point for your code! It's all 'boiler plate' code, so there's no reason to rewrite it.

[Check out the workflow information for how to use our repositories!](https://github.com/CuUwrRobotics/workflow)
