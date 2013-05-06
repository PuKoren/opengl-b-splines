opengl-b-splines
================

Learning B-Splines with OpenGL


Dependencies:
================
####Debian users:
apt-get install freeglut3-dev libxmu-dev libxi-dev

####Windows users:
MinGW with MSYS and g++ compiler

Cmake installed on Cygwin

######This program needs OpenGL libs to run.


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