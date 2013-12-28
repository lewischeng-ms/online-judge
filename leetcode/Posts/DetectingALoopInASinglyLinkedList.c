#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag {
	int val;
	struct node_tag *next;
} node_t, *pnode_t;

void print_loop(pnode_t head) {
	int n = 0;
	while (head && n < 100) {
		printf("%d ", head->val);
		head = head->next;
		++n;
	}
	printf(" ...\n");
}

int has_cycle(pnode_t head) {
	pnode_t slow = head;
	pnode_t fast = head;
	while (fast) {
		slow = slow->next;
		fast = fast->next ? fast->next->next : NULL;
		if (slow == fast)
			return 1;
	}
	return 0;
}

int main() {
	node_t nodes[] = {
		{ 2, &nodes[1] },
		{ 3, &nodes[2] },
		{ 5, &nodes[3] },
		{ 7, &nodes[4] },
		{ 9, &nodes[2] }
	};

	printf("List:\n");
	print_loop(nodes);

	printf("Has Cycle: %d\n", has_cycle(&nodes[0]));
	return 0;
}