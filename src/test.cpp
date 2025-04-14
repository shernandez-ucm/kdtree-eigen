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
    int axis=0;
    std::sort(data.begin(), data.end(), [axis](const Point& a, const Point& b) {
            return a(axis) < b(axis);
        });
    for(int i=0;i<data.size();i++){
          std::cout << "Point: " << data[i].transpose() << "\n";
    }
    std::cout << "-------------------" <<std::endl;
    KDTree tree(data);
    std::cout << "-------------------" <<std::endl;
    tree.print();

    return 0;
}