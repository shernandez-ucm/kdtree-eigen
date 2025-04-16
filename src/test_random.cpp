#include <iostream>
#include <vector>
#include <memory>
#include <Eigen/Dense>
#include <cmath>
using namespace std::chrono;
#include "kdtree.cpp"

using namespace Eigen;
using Point = VectorXd;
//constexpr int NUM_POINTS = 20;
int main(int argc, char* argv[]) {
    int dim=atoi(argv[2]);
    int num_points=atoi(argv[1]);
    int K=atoi(argv[3]);
    std::vector<Point> data;
    for(int i=0;i<num_points;i++){
        Point point(dim);
        point.setRandom();
        data.push_back(point);
    }
    auto start1=high_resolution_clock::now();
    KDTree tree(data);
    auto end1=high_resolution_clock::now();
    auto build_time=duration_cast<milliseconds>(end1-start1).count();
    VectorXd query = VectorXd(dim);
    query.setRandom();
    auto start2=high_resolution_clock::now();
    std::vector<VectorXd> neighbors=tree.kNearestNeighbors(query,K);
    auto end2=high_resolution_clock::now();
    auto query_time=duration_cast<milliseconds>(end2-start2).count();
    std::cout << "-------------------" <<std::endl;
    std::cout << "N : " << num_points << ", D : " << dim  << ", K : " << K << ", Build : " << build_time << "[ms], Query : " << query_time   << "[ms]"<< std::endl;
    return 0;
}