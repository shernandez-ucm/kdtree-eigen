# KD-tree Eigen
The KD-Tree (k-dimensional tree) implementation using Eigen is designed to efficiently organize points in multi-dimensional space. The tree is built recursively by selecting a splitting axis at each depth (cycling through dimensions), sorting the data along that axis, and choosing the median point as the node. This approach ensures a balanced structure in the average case. The points are stored using Eigen::VectorXd (or Vector2d, Vector3d, etc.), allowing seamless linear algebra operations like distance calculations.

## Compilation Instruction
Ensure you have the Eigen library installed and accessible. Open a terminal and navigate to the project folder

`cd kdtree-eigen`

Modify the `CmakeLists.txt` file to match the compiler and the location of the Eigen library.
```
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project (kdtree)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(EIGEN_ROOT_DIR "../eigen/")

include_directories(
    ${EIGEN_ROOT_DIR}
)
add_executable (kdtree_test src/kdtree.cpp  src/test.cpp )
```
Compile using `cmake`

```
cmake ./
make
```