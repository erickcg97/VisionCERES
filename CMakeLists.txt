# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Define project name
project(VisionCERES_project)

set(raspicam_DIR "/usr/local/lib/cmake")
# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)



# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "COMPILING OPENCV TESTS")
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
 
if(CMAKE_VERSION VERSION_LESS "2.8.11")
  # Add OpenCV headers location to your include paths
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

include_directories(${WIRINGPI_INCLUDE_DIRS})

# Declare the executable target built from your sources
add_executable(main main.cpp linhas.h)

#find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

# Link your application with OpenCV libraries
target_link_libraries(main ${OpenCV_LIBS})
#target_link_libraries(testesFURG ${WIRINGPI_LIBRARIES}) 