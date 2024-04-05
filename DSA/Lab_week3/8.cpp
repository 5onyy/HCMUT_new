// lass BTNode is used to store a node in binary tree, described on the following:

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

// Request: Implement function:

// int longestPathSum(BTNode* root);
// Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). This function returns the sum of the largest path from the root node to a leaf node. If there are more than one equally long paths, return the larger sum.

// Example:

// Given a binary tree in the following:

// longestPathSum

// The longest path from the root node to the leaf node is 1-4-7-4-2, so return the sum of this path, is 18.


// Explanation of function createTree: The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.

// Example:

// int arr[] = {-1,0,0,2,2};
// int value[] = {3,5,2,1,4};
// BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
// arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
// Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.

// Note: In this exercise, the libraries iostream, utility, queue, stack and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

std::pair<int, int> longestPathSumHelper(BTNode* root) {
    if (!root) return {0, 0};

    std::pair<int, int> left = longestPathSumHelper(root->left);
    std::pair<int, int> right = longestPathSumHelper(root->right);

    if (left.first == right.first) {
        return {left.first + 1, std::max(left.second, right.second) + root->val};
    } else if (left.first > right.first) {
        return {left.first + 1, left.second + root->val};
    } else {
        return {right.first + 1, right.second + root->val};
    }
}

int longestPathSum(BTNode* root) {
    std::pair<int, int> result = longestPathSumHelper(root);
    return result.second;}