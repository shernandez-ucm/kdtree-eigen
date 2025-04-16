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
    VectorXd query = Vector2d(8.0, 3.0);
    std::vector<VectorXd> neighbors=tree.kNearestNeighbors(query,2);
    std::cout << "-------------------" <<std::endl;
    std::cout << "query : " << query.transpose()  << ", neighbors : " << neighbors.size() << std::endl;
    for(int i=0;i<neighbors.size();i++){
        std::cout << "point : " << neighbors[i].transpose() << std::endl;
    }
    return 0;
}