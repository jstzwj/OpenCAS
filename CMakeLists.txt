cmake_minimum_required(VERSION 2.8.12)
project(OpenCAS)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

ADD_SUBDIRECTORY(source)
ADD_SUBDIRECTORY(examples)