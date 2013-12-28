#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag {
	int val;
	struct node_tag *next;
} node_t, *pnode_t;

void split(pnode_t head, pnode_t *front, pnode_t *back) {
	pnode_t p = head;
	pnode_t pre = NULL;
	pnode_t q = head;
	while (q) {
		pre = p;
		p = p->next;
		q = q->next ? q->next->next : NULL;
	}
	if (pre) pre->next = 0;
	*front = head;
	*back = p;
}

void print(pnode_t head) {
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int main() {
	node_t nodes[] = {
		{ 2, &nodes[1] },
		{ 3, &nodes[2] },
		{ 5, &nodes[3] },
		{ 7, &nodes[4] },
		{ 11, NULL}
	};

	printf("Original:\n");
	print(nodes);

	pnode_t front = NULL;
	pnode_t back = NULL;
	split(&nodes[0], &front, &back);

	printf("Front:\n");
	print(front);

	printf("Back:\n");
	print(back);

	return 0;
}