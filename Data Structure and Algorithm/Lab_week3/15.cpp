// Class BTNode is used to store a node in binary search tree, described on the following:

// class BTNode {
//     public: 
//         int val; 
//         BTNode *left; 
//         BTNode *right; 
//         BTNode() {
//             this->left = this->right = NULL;
//         } 
//         BTNode(int val) {
//             this->val = val;
//             this->left = this->right = NULL;
//         } 
//         BTNode(int val, BTNode*& left, BTNode*& right) {
//             this->val = val;
//             this->left = left;
//             this->right = right;
//         } 
// };
// Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.

// Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:

// int arr[] = {0, 10, 20, 30};
// auto root = BSTNode::createBSTree(arr, arr + 4);
// is equivalent to

// auto root = new BSTNode(0);
// root->addNode(10);
// root->addNode(20);
// root->addNode(30);
// Request: Implement function:

// int rangeCount(BTNode* root, int lo, int hi);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements), lo and hi are 2 positives integer and lo ≤ hi. This function returns the number of all nodes whose values are between [lo, hi] in this binary search tree.

// More information:

// - If a node has val which is equal to its ancestor's, it is in the right subtree of its ancestor.

// Example:

// Given a binary search tree in the following:

// RangeCount

// With lo=5, hi=10, all the nodes satisfied are node 9, 7, 8; there fore, the result is 3.

// Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.
int rangeCountHelper(BTNode* root, int lo, int hi) {
    if (!root) return 0;

    if (root->val >= lo && root->val <= hi) {
        return 1 + rangeCountHelper(root->left, lo, hi) + rangeCountHelper(root->right, lo, hi);
    } else if (root->val < lo) {
        return rangeCountHelper(root->right, lo, hi);
    } else {  // root->val > hi
        return rangeCountHelper(root->left, lo, hi);
    }
}

int rangeCount(BTNode* root, int lo, int hi) {
    return rangeCountHelper(root, lo, hi);
}
