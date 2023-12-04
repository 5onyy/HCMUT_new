// Class BTNode is used to store a node in binary tree, described on the following:

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
// Where val is the value of node (integer, in segment [0,9]), left and right are the pointers to the left node and right node of it, respectively.

// Request: Implement function:

// int sumDigitPath(BTNode* root);
// Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the sum of all digit path numbers of this binary tree (the result may be large, so you must use mod 27022001 before returning).

// More information:

// - A path is called as digit path if it is a path from the root node to the leaf node of the binary tree.

// - Each digit path represents a number in order, each node's val of this path is a digit of this number, while root's val is the first digit.

// Example:

// Given a binary tree in the following:

// SumDigitPath

// All of the digit paths are 3-5, 3-2-1, 3-2-4; and the number reprensted by them are 35, 321, 324, respectively. The sum of them (after mod 27022001) is 680.

// Explanation of function createTree: The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.

// Example:

// int arr[] = {-1,0,0,2,2};
// int value[] = {3,5,2,1,4};
// BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
// arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
// Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.
// Note: In this exercise, the libraries iostream, queue, stack, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

int helper(BTNode* root, int currentSum) {
    if (!root) return 0;
    currentSum = (currentSum * 10 + root->val) % 27022001;
    
    // If it's a leaf node
    if (!root->left && !root->right) {
        return currentSum;
    }
    
    return (helper(root->left, currentSum) + helper(root->right, currentSum)) % 27022001;
}

int sumDigitPath(BTNode* root) {
    return helper(root, 0);
}