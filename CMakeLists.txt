cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project (kdtree)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(EIGEN_ROOT_DIR "../eigen/")

include_directories(
    ${EIGEN_ROOT_DIR}
)
add_executable (kdtree_test src/kdtree.cpp  src/test.cpp )
