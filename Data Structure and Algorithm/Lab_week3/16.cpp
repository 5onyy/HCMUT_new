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

// int singleChild(BSTNode* root);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the number of single children in the tree.

// More information:

// - A node is called a single child if its parent has only one child.

// Example:

// Given a binary search tree in the following:

// singleChild
// There are 2 single children: node 2 and node 3.

// Note: In this exercise, the libraries iostream and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

// For example:

// Test	Result
// int arr[] = {0, 3, 5, 1, 2, 4};
// BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr)/sizeof(int));
// cout << singleChild(root);
// BSTNode::deleteTree(root);
int singleChild(BSTNode* root) {
    if (!root) return 0;

    int count = 0;

    // Check if node has only one child
    if ((root->left && !root->right) || (!root->left && root->right)) {
        count = 1;
    }

    return count + singleChild(root->left) + singleChild(root->right);
}