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
