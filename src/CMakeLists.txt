cmake_minimum_required(VERSION 3.14)

project(IntersectProject)

set(INTERSECT_FILES space.cc)

add_library(intersect_lib STATIC ${INTERSECT_FILES})


