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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode sentinel(0);
        ListNode *last = &sentinel;
        ListNode *first = head;
        ListNode *second;
        while (first) {
            second = first->next;
        	if (second) {
        		ListNode *newFirst = second->next;
        		first->next = 0;
        		second->next = first;
        		last->next = second;
        		last = first;
        		first = newFirst;
        	} else {
        		last->next = first;
        		last = first;
        		first = 0;
        	}
        }
        return sentinel.next;
    }
};