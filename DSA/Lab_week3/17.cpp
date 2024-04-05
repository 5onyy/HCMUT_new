// Class BSTNode is used to store a node in binary search tree, described on the following:

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

// BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the binary search tree after deleting all nodes whose values are outside the range [lo, hi] (inclusive).

// Example:

// Given a binary search tree in the following:

// subtree
// With lo = 7 and hi = 10, the result should be:

// subtreeres
// Note: In this exercise, the libraries iostream and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

// For example:

// Test	Result
// int arr[] = {0, 3, 5, 1, 2, 4};
// int lo = 1, hi = 3;
// BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr)/sizeof(int));
// root = subtreeWithRange(root, lo, hi);
// BSTNode::printPreorder(root);
// BSTNode::deleteTree(root);
// 3 1 2 

BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (!root) return nullptr;
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    if (root->val < lo || root->val > hi) {
        BSTNode* temp = nullptr;
        if (root->left) temp = root->left;
        else temp = root->right;
        delete root;
        return temp;
    }
    return root;
}