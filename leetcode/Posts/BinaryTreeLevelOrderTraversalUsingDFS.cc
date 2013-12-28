void printLevel(BinaryTree *p, int level) {
  if (!p) return;
  if (level == 1) {
    cout << p->data << " ";
  } else {
    printLevel(p->left, level-1);
    printLevel(p->right, level-1);
  }
}

void printLevelOrder(BinaryTree *root) {
  int height = maxHeight(root);
  for (int level = 1; level <= height; level++) {
    printLevel(root, level);
    cout << endl;
  }
}

/* 此算法时间复杂度只有O(n)，证明：
T(k) = 2T(k-1) + c
     = 2^k-1 T(1) + c
     = 2^k-1 + c
T(1) + T(2) + ... + T(lg N)
= 1 + 2 + 2^2 + ... + 2^lg N-1 + c
= O(N) */