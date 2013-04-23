# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/koren/Dev/c++/OpenGL/opengl-b-splines

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin

# Include any dependencies generated for this target.
include CMakeFiles/BSplines.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BSplines.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BSplines.dir/flags.make

CMakeFiles/BSplines.dir/maths/Vector2.cpp.o: CMakeFiles/BSplines.dir/flags.make
CMakeFiles/BSplines.dir/maths/Vector2.cpp.o: ../maths/Vector2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/BSplines.dir/maths/Vector2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BSplines.dir/maths/Vector2.cpp.o -c /home/koren/Dev/c++/OpenGL/opengl-b-splines/maths/Vector2.cpp

CMakeFiles/BSplines.dir/maths/Vector2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BSplines.dir/maths/Vector2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/koren/Dev/c++/OpenGL/opengl-b-splines/maths/Vector2.cpp > CMakeFiles/BSplines.dir/maths/Vector2.cpp.i

CMakeFiles/BSplines.dir/maths/Vector2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BSplines.dir/maths/Vector2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/koren/Dev/c++/OpenGL/opengl-b-splines/maths/Vector2.cpp -o CMakeFiles/BSplines.dir/maths/Vector2.cpp.s

CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.requires:
.PHONY : CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.requires

CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.provides: CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.requires
	$(MAKE) -f CMakeFiles/BSplines.dir/build.make CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.provides.build
.PHONY : CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.provides

CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.provides.build: CMakeFiles/BSplines.dir/maths/Vector2.cpp.o

CMakeFiles/BSplines.dir/Application.cpp.o: CMakeFiles/BSplines.dir/flags.make
CMakeFiles/BSplines.dir/Application.cpp.o: ../Application.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/BSplines.dir/Application.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BSplines.dir/Application.cpp.o -c /home/koren/Dev/c++/OpenGL/opengl-b-splines/Application.cpp

CMakeFiles/BSplines.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BSplines.dir/Application.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/koren/Dev/c++/OpenGL/opengl-b-splines/Application.cpp > CMakeFiles/BSplines.dir/Application.cpp.i

CMakeFiles/BSplines.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BSplines.dir/Application.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/koren/Dev/c++/OpenGL/opengl-b-splines/Application.cpp -o CMakeFiles/BSplines.dir/Application.cpp.s

CMakeFiles/BSplines.dir/Application.cpp.o.requires:
.PHONY : CMakeFiles/BSplines.dir/Application.cpp.o.requires

CMakeFiles/BSplines.dir/Application.cpp.o.provides: CMakeFiles/BSplines.dir/Application.cpp.o.requires
	$(MAKE) -f CMakeFiles/BSplines.dir/build.make CMakeFiles/BSplines.dir/Application.cpp.o.provides.build
.PHONY : CMakeFiles/BSplines.dir/Application.cpp.o.provides

CMakeFiles/BSplines.dir/Application.cpp.o.provides.build: CMakeFiles/BSplines.dir/Application.cpp.o

CMakeFiles/BSplines.dir/main.cpp.o: CMakeFiles/BSplines.dir/flags.make
CMakeFiles/BSplines.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/BSplines.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BSplines.dir/main.cpp.o -c /home/koren/Dev/c++/OpenGL/opengl-b-splines/main.cpp

CMakeFiles/BSplines.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BSplines.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/koren/Dev/c++/OpenGL/opengl-b-splines/main.cpp > CMakeFiles/BSplines.dir/main.cpp.i

CMakeFiles/BSplines.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BSplines.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/koren/Dev/c++/OpenGL/opengl-b-splines/main.cpp -o CMakeFiles/BSplines.dir/main.cpp.s

CMakeFiles/BSplines.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/BSplines.dir/main.cpp.o.requires

CMakeFiles/BSplines.dir/main.cpp.o.provides: CMakeFiles/BSplines.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BSplines.dir/build.make CMakeFiles/BSplines.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BSplines.dir/main.cpp.o.provides

CMakeFiles/BSplines.dir/main.cpp.o.provides.build: CMakeFiles/BSplines.dir/main.cpp.o

# Object files for target BSplines
BSplines_OBJECTS = \
"CMakeFiles/BSplines.dir/maths/Vector2.cpp.o" \
"CMakeFiles/BSplines.dir/Application.cpp.o" \
"CMakeFiles/BSplines.dir/main.cpp.o"

# External object files for target BSplines
BSplines_EXTERNAL_OBJECTS =

BSplines: CMakeFiles/BSplines.dir/maths/Vector2.cpp.o
BSplines: CMakeFiles/BSplines.dir/Application.cpp.o
BSplines: CMakeFiles/BSplines.dir/main.cpp.o
BSplines: CMakeFiles/BSplines.dir/build.make
BSplines: /usr/lib/x86_64-linux-gnu/libGLU.so
BSplines: /usr/lib/x86_64-linux-gnu/libGL.so
BSplines: /usr/lib/x86_64-linux-gnu/libSM.so
BSplines: /usr/lib/x86_64-linux-gnu/libICE.so
BSplines: /usr/lib/x86_64-linux-gnu/libX11.so
BSplines: /usr/lib/x86_64-linux-gnu/libXext.so
BSplines: /usr/lib/x86_64-linux-gnu/libglut.so
BSplines: /usr/lib/x86_64-linux-gnu/libXmu.so
BSplines: /usr/lib/x86_64-linux-gnu/libXi.so
BSplines: CMakeFiles/BSplines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable BSplines"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BSplines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BSplines.dir/build: BSplines
.PHONY : CMakeFiles/BSplines.dir/build

CMakeFiles/BSplines.dir/requires: CMakeFiles/BSplines.dir/maths/Vector2.cpp.o.requires
CMakeFiles/BSplines.dir/requires: CMakeFiles/BSplines.dir/Application.cpp.o.requires
CMakeFiles/BSplines.dir/requires: CMakeFiles/BSplines.dir/main.cpp.o.requires
.PHONY : CMakeFiles/BSplines.dir/requires

CMakeFiles/BSplines.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BSplines.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BSplines.dir/clean

CMakeFiles/BSplines.dir/depend:
	cd /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/koren/Dev/c++/OpenGL/opengl-b-splines /home/koren/Dev/c++/OpenGL/opengl-b-splines /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin /home/koren/Dev/c++/OpenGL/opengl-b-splines/bin/CMakeFiles/BSplines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BSplines.dir/depend
