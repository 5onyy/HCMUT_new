//Helping functions
 // Find the correct postion and insert the node


int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeightRec(node->pLeft) - getHeightRec(node->pRight);
}

Node *rotateRight(Node *y) {
    Node *x = y->pLeft;
    Node *T2 = x->pRight;
    x->pRight = y;
    y->pLeft = T2;
    return x;
}

// Rotate left
Node *rotateLeft(Node *x) {
    Node *y = x->pRight;
    Node *T2 = y->pLeft;
    y->pLeft = x;
    x->pRight = T2;
    return y;
}
 
 
 
 Node *insertNode(Node *node, const T& key) {
  if (node == NULL)
    return (new Node(key));
  if (key < node->data)
    node->pLeft = insertNode(node->pLeft, key);
  else if (key >= node->data)
    node->pRight = insertNode(node->pRight, key);


  // Update the balance factor of each node and
  // balance the tree
 /* node->height = 1 + max(height(node->pLeft),
               height(node->pRight));*/
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->pLeft->data) {
      return rotateRight(node);
    } else if (key >= node->pLeft->data) {
      node->pLeft = rotateLeft(node->pLeft);
      return rotateRight(node);
    }
  }
  if (balanceFactor < -1) {
    if (key >= node->pRight->data) {
      return rotateLeft(node);
    } else if (key < node->pRight->data) {
      node->pRight = rotateRight(node->pRight);
      return rotateLeft(node);
    }
  }
  return node;
}


void insert(const T &value){
    //TODO
    root=insertNode(root,value);
}
