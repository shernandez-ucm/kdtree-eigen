#include <iostream>
#include <vector>
#include <memory>
#include <Eigen/Dense>
#include <cmath>
#include <chrono>
#include "kdtree.cpp"

using namespace Eigen;
using Point = VectorXd;
//constexpr int NUM_POINTS = 20;
int main(int argc, char* argv[]) {
    int dim=atoi(argv[2]);
    int num_points=atoi(argv[1]);
    int K=atoi(argv[3]);
    int LeafSize=atoi(argv[4]);
    std::vector<Point> data;
    for(int i=0;i<num_points;i++){
        Point point(dim);
        point.setRandom();
        data.push_back(point);
    }
    auto start1=std::chrono::high_resolution_clock::now();
    KDTree tree(data,0,LeafSize);
    auto end1=std::chrono::high_resolution_clock::now();
    auto build_time=std::chrono::duration_cast<std::chrono::milliseconds>(end1-start1).count();
    VectorXd query = VectorXd(dim);
    query.setRandom();
    auto start2=std::chrono::high_resolution_clock::now();
    std::vector<VectorXd> neighbors=tree.kNearestNeighbors(query,K);
    auto end2=std::chrono::high_resolution_clock::now();
    auto query_time=std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2).count();
    std::cout << "-------------------" <<std::endl;
    std::cout << "N : " << num_points << ", D : " << dim  << ", K : " << K << ", Build : " << build_time << "[ms], Query : " << query_time   << "[ms]"<< std::endl;
    return 0;
}