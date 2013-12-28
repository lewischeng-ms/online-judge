void inorder(BinaryTree *root) {
	stack<BinaryTree *> s;
	BinaryTree *current = root;
	while (!s.empty() || current) {
		if (current) {
			s.push(current);
			current = current->left;
		} else {
			current = s.top();
			s.pop();
			cout << current->data << endl;
			current = current->right;
		}
	}
}