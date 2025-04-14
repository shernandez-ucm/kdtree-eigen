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
    std::cout << "-------------------" <<std::endl;
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