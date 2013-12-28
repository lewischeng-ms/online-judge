struct Node {
	Node *leftChild;
	Node *rightChild;
	Node *nextRight;
};

void helper(Node *p) {
	if (p->leftChild) {
		p->leftChild->nextRight = p->rightChild;
		helper(p->leftChild);
	}

	if (p->rightChild) {
		p->rightChild->nextRight = p->nextRight ?
			p->nextRight->leftChild : 0;
		helper(p->rightChild);
	}
}

void connect(Node *p) {
	if (!p) return;
	p->nextRight = 0;
	helper(p);
}