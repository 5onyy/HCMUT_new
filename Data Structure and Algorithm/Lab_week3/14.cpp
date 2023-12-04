// lass BSTNode is used to store a node in binary search tree, described on the following:

// class BSTNode {
// public: 
//     int val; 
//     BSTNode *left; 
//     BSTNode *right; 
//     BSTNode() {
//         this->left = this->right = nullptr;
//     } 
//     BSTNode(int val) {
//         this->val = val;
//         this->left = this->right = nullptr;
//     } 
//     BSTNode(int val, BSTNode*& left, BSTNode*& right) {
//         this->val = val;
//         this->left = left;
//         this->right = right;
//     } 
// };
// Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.

// Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:

// int arr[] = {0, 10, 20, 30};
// auto root = BSTNode::createBSTree(arr, arr + 4);
// is equivalent to

// auto root = new BSTNode(0);
// root->addNode(10);
// root->addNode(20);
// root->addNode(30);
// Request: Implement function:

// int kthSmallest(BSTNode* root, int k);
// Where root is the root node of given binary search tree (this tree has n elements) and k satisfy: 1 <= k <= n <= 100000. This function returns the k-th smallest value in the tree.

// Example:

// Given a binary search tree in the following:

// minimum
// With k = 2, the result should be 1.

// Note: In this exercise, the libraries iostream, vector, stack, queue, algorithm, climits and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

int kthSmallestHelper(BSTNode* root, int &k) {
    if (!root) return -1;
    
    int left = kthSmallestHelper(root->left, k);
    if (k == 0) return left;  // Found in left subtree

    if (--k == 0) return root->val;  // Current node is the kth smallest

    return kthSmallestHelper(root->right, k);
}

int kthSmallest(BSTNode* root, int k) {
    return kthSmallestHelper(root, k);
}