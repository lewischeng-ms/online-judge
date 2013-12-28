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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode handleBefore(0);
        ListNode handleAfter(0);
        ListNode *lastBefore = &handleBefore;
        ListNode *lastAfter = &handleAfter;
        while (head) {
        	ListNode *next = head->next;
        	head->next = 0;
        	if (head->val < x) {
        		lastBefore->next = head;
        		lastBefore = head;
        	} else {
        		lastAfter->next = head;
        		lastAfter = head;
        	}
        	head = next;
        }
        lastBefore->next = handleAfter.next;
        return handleBefore.next;
    }
};