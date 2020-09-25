<!--
@Author: Nick Steele <nichlock>
@Date:   21:37 Sep 18 2020
@Last modified by:   nichlock
@Last modified time: 19:07 Sep 19 2020
-->

# HOW TO SET UP THIS TEMPLATE
- [ ] Click 'Use this template' and create your repository (check our [workflow information](https://github.com/CuUwrRobotics/workflow) for more on naming repositories first!) 
- [ ] Run the code from file setup/labels.json in Chrome's Inspect Element console while on the GitHub [labels](../../labels) page to update all labels
- [ ] If the submodules are not included (if you can't see the folders `ros-docker` and `catkin-setups`), run these commands from your console in the repository:
  - [ ] `git submodule add https://github.com/CuUwrRobotics/ros-docker.git`
  - [ ] `git submodule add https://github.com/CuUwrRobotics/catkin-setups.git`
- [ ] Add a `.gitignore` if needed
- [ ] Delete `setup/*` directory and files
- [ ] Update this readme with a description of your program and any particulars of using it

[Check out the workflow information for how to use our repositories!](https://github.com/CuUwrRobotics/workflow)
