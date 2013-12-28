bool isBSTHelper(BinaryTree *p, int low, int high) {
  if (!p) return true;
  if (low < p->data && p->data < high)
    return isBSTHelper(p->left, low, p->data) && 
           isBSTHelper(p->right, p->data, high);
  else
    return false;
}
 
bool isBST(BinaryTree *root) {
  // INT_MIN and INT_MAX are defined in C++'s <climits> library
  return isBSTHelper(root, INT_MIN, INT_MAX);  
}