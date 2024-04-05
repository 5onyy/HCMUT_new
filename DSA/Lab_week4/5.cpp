//Helping functions
Node * maxValueNode(Node* node) 
{ 
    Node* current = node; 
 
    while (current->pRight != NULL) 
        current = current->pRight; 
 
    return current; 
} 
 
int getBalance(Node * node) {
    return this->getHeightRec(node->pLeft) - this->getHeightRec(node->pRight);
}
Node* deleteNode(Node* root, int key) 
{ 
     
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root; 
 
    if ( key < root->data ) 
        root->pLeft = deleteNode(root->pLeft, key); 
 
    else if( key > root->data ) 
        root->pRight = deleteNode(root->pRight, key); 
 
    else
    { 
        // node with only one child or no child 
        if( (root->pLeft == NULL) ||
            (root->pRight == NULL) ) 
        { 
            Node *temp = root->pLeft ?  root->pLeft : root->pRight; 
 
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else  *root = *temp; 
            delete temp; 
        } 
        else
        { 
            Node* temp = maxValueNode(root->pLeft); 
            root->data = temp->data; 
            root->pLeft = deleteNode(root->pLeft, temp->data); 
        } 
    } 
 
    // If the tree had only one node
    // then return 
    if (root == NULL) 
    return root; 
 
    int balance = getBalance(root); 
 
    // If this node becomes unbalanced, 
    // then there are 4 cases 
 
    // Left Left Case 
    if (balance > 1 && getBalance(root->pLeft) >= 0) 
        return rotateRight(root); 
 
    // Left Right Case 
    if (balance > 1 && getBalance(root->pLeft) < 0) 
    { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && getBalance(root->pRight) <= 0) 
        return rotateLeft(root); 
 
    // Right Left Case 
    if (balance < -1 && getBalance(root->pRight) > 0) 
    { 
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    } 
 
    return root; 
} 
void remove(const T &value){
    //TODO
    root = deleteNode(root,value);
}
