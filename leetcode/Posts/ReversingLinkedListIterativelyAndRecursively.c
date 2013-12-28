#include <stdio.h>

struct Node {
	Node *next;
	int val;
};

Node *reverse_itr(Node* head) {
	Node *front = 0;
	while (head) {
		Node *next = head->next;
		head->next = front;
		front = head;
		head = next;
	}
	return front;
}

Node *reverse_rec(Node *head) {
	if (!head) return NULL;
	if (head->next) {
		Node *p = reverse_rec(head->next);
		head->next->next = head;
		head->next = 0;
		return p;
	}
	return head;
}

int main() {
	Node nodes[3];
	nodes[0].val = 1; nodes[0].next = &nodes[1];
	nodes[1].val = 2; nodes[1].next = &nodes[2];
	nodes[2].val = 3; nodes[2].next = 0;
	//Node *p = reverse_rec(&nodes[0]);
	Node *p = reverse_itr(&nodes[0]);
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	return 0;
}