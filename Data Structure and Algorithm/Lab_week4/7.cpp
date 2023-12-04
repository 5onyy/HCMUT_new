    void printInorder(){
        if (!root)  return;
        printInorderRecursive(root);
        cout << " ";  // Add a whitespace at the end
    }

    bool search(const T &value){
        return searchRecursive(root, value);
    }

    void printInorderRecursive(Node* node) {
        if (node != nullptr) {
            printInorderRecursive(node->pLeft);
            cout << node->data << " ";
            printInorderRecursive(node->pRight);
        }
    }

    bool searchRecursive(Node* node, const T &value) {
        if (node == nullptr)
            return false;

        if (value == node->data)
            return true;
        else if (value < node->data)
            return searchRecursive(node->pLeft, value);
        else
            return searchRecursive(node->pRight, value);
    }

