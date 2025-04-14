# KD-tree Eigen
The KD-Tree (k-dimensional tree) implementation using Eigen is designed to efficiently organize points in multi-dimensional space. The tree is built recursively by selecting a splitting axis at each depth (cycling through dimensions), sorting the data along that axis, and choosing the median point as the node. This approach ensures a balanced structure in the average case. The points are stored using Eigen::VectorXd (or Vector2d, Vector3d, etc.), allowing seamless linear algebra operations like distance calculations.

## Compilation Instruction
Ensure you have the Eigen library installed and accessible. Open a terminal and navigate to the project folder

`cd kdtree-eigen`

Modify the `CmakeLists.txt` file to match the compiler and location of the Eigen library.
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

## Usage

```
#include <iostream>
#include <vector>
#include <memory>
#include <Eigen/Dense>
#include <cmath>
#include "kdtree.cpp"

using namespace Eigen;
using Point = VectorXd;

int main() {
    std::vector<Point> data = {
        Vector2d(2.0, 3.0),
        Vector2d(5.0, 4.0),
        Vector2d(9.0, 6.0),
        Vector2d(4.0, 7.0),
        Vector2d(8.0, 1.0),
        Vector2d(7.0, 2.0)
    };
    KDTree tree(data);
    std::cout << "-------------------" <<std::endl;
    tree.print();
    std::cout << "-------------------" <<std::endl;
    VectorXd query = Vector2d(5.0, 3.0);
    double min_dist=tree.kNearestNeighbors(query);
    std::cout << "-------------------" <<std::endl;
    std::cout << "query : " << query.transpose()  << ", distance : " << min_dist << std::endl;
    return 0;
}
```