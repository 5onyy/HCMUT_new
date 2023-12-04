// In this question, you have to perform add and delete on binary search tree. Note that:

// - When deleting a node which still have 2 children, take the inorder successor (smallest node of the right sub tree of that node) to replace it.

// - When adding a node which has the same value as parent node, add it in the left sub tree.

// Your task is to implement two functions: add and deleteNode. You could define one or more functions to achieve this task.

// #include <iostream>
// #include <string>
// #include <sstream>
// using namespace std;
// #define SEPARATOR "#<ab@17943918#@>#"
// template<class T>
// class BinarySearchTree
// {
// public:
//     class Node;
// private:
//     Node* root;
// public:
//     BinarySearchTree() : root(nullptr) {}
//     ~BinarySearchTree()
//     {
//         // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
//     }

//     //Helping function

//     void add(T value){
//         //TODO
//     }
   
//     void deleteNode(T value){
//         //TODO
//     }
//     string inOrderRec(Node* root) {
//         stringstream ss;
//         if (root != nullptr) {
//             ss << inOrderRec(root->pLeft);
//             ss << root->value << " ";
//             ss << inOrderRec(root->pRight);
//         }
//         return ss.str();
//     }
    
//     string inOrder(){
//         return inOrderRec(this->root);
//     }
    
//     class Node
//     {
//     private:
//         T value;
//         Node* pLeft, * pRight;
//         friend class BinarySearchTree<T>;
//     public:
//         Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
//         ~Node() {}
//     };
// };

// For example:

// Test	Result
// BinarySearchTree<int> bst;
// bst.add(9);
// bst.add(2);
// bst.add(10);
// bst.deleteNode(9);
// cout << bst.inOrder();
// 2 10 
// BinarySearchTree<int> bst;
// bst.add(9);
// bst.add(2);
// bst.add(10);
// bst.add(8);
// cout << bst.inOrder()<<endl;
// bst.add(11);
// bst.deleteNode(9);
// cout << bst.inOrder();
// 2 8 9 10 
// 2 8 10 11 

//Helping functions
 Node* addRec(Node* node, T value) {
            if (!node) return new Node(value);
            if (value <= node->value) node->pLeft = addRec(node->pLeft, value);
            else node->pRight = addRec(node->pRight, value);
            return node;
        }

        Node* findMin(Node* node) {
            while (node->pLeft) node = node->pLeft;
            return node;
        }

        Node* deleteRec(Node* root, T value) {
            if (!root) return root;
            if (value < root->value) root->pLeft = deleteRec(root->pLeft, value);
            else if (value > root->value) root->pRight = deleteRec(root->pRight, value);
            else {
                if (!root->pLeft) {
                    Node* temp = root->pRight;
                    delete root;
                    return temp;
                }
                else if (!root->pRight) {
                    Node* temp = root->pLeft;
                    delete root;
                    return temp;
                }
                Node* temp = findMin(root->pRight);
                root->value = temp->value;
                root->pRight = deleteRec(root->pRight, temp->value);
            }
            return root;
        }
 void add(T value) {
            root = addRec(root, value);
        }
       
        void deleteNode(T value) {
            root = deleteRec(root, value);
        }