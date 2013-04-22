cmake_minimum_required (VERSION 2.6)
project (BSplines) 

#########################################################
# FIND GLUT
#########################################################
find_package (GLUT REQUIRED)
include_directories (${GLUT_INCLUDE_DIRS})
link_directories (${GLUT_LIBRARY_DIRS})
add_definitions (${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message (ERROR " GLUT not found!")
endif (NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package (OpenGL REQUIRED)
include_directories (${OpenGL_INCLUDE_DIRS})
link_directories (${OpenGL_LIBRARY_DIRS})
add_definitions (${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message (ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)

add_executable (BSplines Application.cpp main.cpp)

########################################################
# Linking & stuff
#########################################################
target_link_libraries (BSplines ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
