#include <iostream>
#include <vector>
#include <memory>
#include <Eigen/Dense>
#include <queue>
#include <cmath>


using namespace Eigen;
using Point = VectorXd;
using Neighbor = std::pair<double, Point>; // {distancia, punto}
using MaxHeap = std::priority_queue<Neighbor>;

struct KDNode {
    Point point;
    std::unique_ptr<KDNode> left;
    std::unique_ptr<KDNode> right;

    KDNode(const Point& pt) : point(pt), left(nullptr), right(nullptr) {}
};

using KDNodePtr = std::unique_ptr<KDNode>;

class KDTree {
public:
    KDTree(const std::vector<Point>& points, int depth = 0) {
        root = build(points, depth);
    }

    KDNodePtr build(std::vector<Point> points, int depth) {
        if (points.empty()) return nullptr;

        int k = points[0].size();
        int axis = depth % k;

        std::sort(points.begin(), points.end(), [axis](const Point& a, const Point& b) {
            return a(axis) < b(axis);
        });

        size_t median_index = points.size() / 2;
        Point median_point = points[median_index];
        std::cout  << "Median Index: " <<  median_index  << ", Depth: " <<  depth  << ", Point: " << median_point.transpose() << "\n";
        std::vector<Point> left_points(points.begin(), points.begin() + median_index);
        std::vector<Point> right_points(points.begin() + median_index + 1, points.end());

        KDNodePtr node = std::make_unique<KDNode>(median_point);
        node->left = build(left_points, depth + 1);
        node->right = build(right_points, depth + 1);

        return node;
    }

    void printTree(KDNodePtr& node, int depth = 0) {
        if (!node) return;
        std::cout << std::string(depth * 2, ' ') << "Point: " << node->point.transpose() << "\n";
        printTree(node->left, depth + 1);
        printTree(node->right, depth + 1);
    }

    void print(){
        printTree(root);
    }

    /*void knnSearch(const KDNodePtr& node, const Point& target, int k, int depth, MaxHeap& heap){
        if (!node) return;
    
        int axis = depth % target.size();
        double dist = (node->point - target).squaredNorm();
    
        // Insertar en la cola si hay espacio o si es más cercano que el peor actual
        if ((int)heap.size() < k) {
            heap.emplace(dist, node->point);
        } else if (dist < heap.top().first) {
            heap.pop();
            heap.emplace(dist, node->point);
        }
    
        // Decidir la rama a visitar primero
        bool goLeft = target(axis) < node->point(axis);
        const KDNodePtr& first = goLeft ? node->left : node->right;
        const KDNodePtr& second = goLeft ? node->right : node->left;
    
        knnSearch(first, target, k, depth + 1, heap);
    
        // Comprobar si es necesario revisar el otro lado del árbol
        double diff = std::pow(target(axis) - node->point(axis), 2);
        if ((int)heap.size() < k || diff < heap.top().first) {
            knnSearch(second, target, k, depth + 1, heap);
        }
    }
    
    // Método público para obtener los k vecinos más cercanos
    std::vector<Point> kNearestNeighbors(const Point& target, int k){
        MaxHeap heap;
        knnSearch(root, target, k, 0, heap);
    
        std::vector<Point> neighbors;
        while (!heap.empty()) {
            neighbors.push_back(heap.top().second);
            heap.pop();
        }
    
        // Opcional: invertir para tener del más cercano al más lejano
        std::reverse(neighbors.begin(), neighbors.end());
        return neighbors;
    } */
    private:
     KDNodePtr root;
};




