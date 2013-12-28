/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		vector<ListNode *> nodes;
		ListNode *it = head;
		while (it) {
			nodes.push_back(it);
			it = it->next;
		}

		if (nodes.size() < 1)
			return;

		ListNode *last = head;
		size_t p = 0;
		size_t q = nodes.size() - 1;
		while (p <= q) {
			if (p != 0) {
				last->next = nodes[p];
				last = nodes[p];
			}

			if (p == q)
				break;
			 
			last->next = nodes[q];
			last = nodes[q];

			++p;
			--q;
		}
		last->next = NULL;
    }
};
