opengl-b-splines
================

Learning B-Splines with OpenGL.

The Spline class use a lot of Paul Bourke C code to draw splines. Thanks to him.
http://paulbourke.net/libraries/paulslib.h


Dependencies (to run binary):
================
####Debian users:
apt-get install freeglut3-dev libxmu-dev libxi-dev

####Windows users:
All should be linked in the .exe so you should not need anything

######This program needs OpenGL libs to run.


Dependencies (to build):
===============
####Debian users:
apt-get install cmake g++ freeglut3-dev libxmu-dev libxi-dev

####Windows users:
MinGW with MSYS and g++ compiler

Cmake installed on Cygwin


Building
========
####Unix:
mkdir build

cd build

cmake ../.

make

####Windows with Cygwin shell:
mkdir build

cd build

cmake -G "MSYS Makefiles" ../.

make
