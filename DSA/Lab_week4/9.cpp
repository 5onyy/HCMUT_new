 Node* searchHelper(Node* p, int val) {
    while (p) {
        if (val == p->val) {
            return p;
        } 
        else if (val < p->val) {
            if (!p -> pLeft)    return p;
            p = p->pLeft;
        } 
        else{
            if (!p -> pRight)   return p;
            p = p->pRight;
        }
    }
    return nullptr;
}  
bool search(int val) {
    Node* result = searchHelper(root, val);
    if (!result)    return 0;
    bool f = result -> val == val;
    splay(result);
    return f;
}

    