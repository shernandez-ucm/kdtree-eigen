# KD-tree Eigen
The KD-Tree (k-dimensional tree) implementation using Eigen is designed to efficiently organize points in multi-dimensional space. The tree is built recursively by selecting a splitting axis at each depth (cycling through dimensions), sorting the data along that axis, and choosing the median point as the node. This approach ensures a balanced structure in the average case. The points are stored using Eigen::VectorXd (or Vector2d, Vector3d, etc.), allowing seamless linear algebra operations like distance calculations.

