# @Author: Nick Steele <nichlock>
# @Date:   21:40 Sep 18 2020
# @Last modified by:   Nick Steele
# @Last modified time: 20:41 Sep 24 2020

echo Copying files...
cd $temporary_package_directory
mkdir /images

# Copy your packages here
# cp -r opencv_ch2/hsv_set $final_package_directory/[package_name]
cp -r test-package/ $final_package_directory/test-package

cp -r images/ /

# Copy our catkin Makefile
cp -r catkin-setups/Makefile $final_package_directory/../Makefile
