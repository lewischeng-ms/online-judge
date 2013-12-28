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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode sentinel(0);
        ListNode *last = &sentinel;
        ListNode *begin = head;
        bool isOver = false;
        while (begin) {
            ListNode *curr = begin;
        	for (int i = 0; i < k; ++i) {
        		if (!curr) {
        			isOver = true;
        			break;
        		} else {
        			curr = curr->next;
        		}
        	}

        	if (isOver) {
        		last->next = begin;
        		break;
        	} else {
        		ListNode *nextK = curr;
        		curr = begin;
        		while (curr != nextK) {
        			ListNode *next = curr->next;
        			curr->next = last->next;
        			last->next = curr;
        			curr = next;
        		}
                last = begin;
        		begin = nextK;
        	}
        }
        return sentinel.next;
    }
};