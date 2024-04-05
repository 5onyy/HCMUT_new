    // Helper function to perform Zig step
    void zig(Node* p) {
        Node* parent = p->pParent;
        if (parent->pLeft == p) {
            parent->pLeft = p->pRight;
            if (p->pRight) p->pRight->pParent = parent;
            p->pRight = parent;
        } else {
            parent->pRight = p->pLeft;
            if (p->pLeft) p->pLeft->pParent = parent;
            p->pLeft = parent;
        }

        p->pParent = parent->pParent;
        parent->pParent = p;

        if (p->pParent) {
            if (p->pParent->pLeft == parent)
                p->pParent->pLeft = p;
            else
                p->pParent->pRight = p;
        } else {
            root = p;
        }
    }

    // Helper function to perform Zig-Zig step
    void zigZig(Node* p) {
        zig(p->pParent);
        zig(p);
    }

    // Helper function to perform Zig-Zag step
    void zigZag(Node* p) {
        zig(p);
        zig(p);
    }

    // Helper function to splay a node to the root
    void splay(Node* p) {
        while (p->pParent) {
            Node* parent = p->pParent;
            Node* grandparent = parent->pParent;

            if (!grandparent) {
                // Zig step
                zig(p);
            } else if ((grandparent->pLeft == parent && parent->pLeft == p) ||
                       (grandparent->pRight == parent && parent->pRight == p)) {
                // Zig-Zig step
                zigZig(p);
            } else {
                // Zig-Zag step
                zigZag(p);
            }
        }
    }
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        // Find the appropriate position to insert the new node
        while (current) {
            parent = current;
            if (val < current->val) {
                current = current->pLeft;
            } else {
                current = current->pRight;
            }
        }

        // Insert the new node
        Node* newNode = new Node(val);
        newNode->pParent = parent;
        if (val < parent->val) {
            parent->pLeft = newNode;
        } else {
            parent->pRight = newNode;
        }

        // Perform splay operation to bring the newly inserted node to the root
        splay(newNode);
    }

