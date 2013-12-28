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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *curr = head;
        while (curr) {
        	int x = curr->val;
        	ListNode *temp = curr;
        	curr = curr->next;
        	while （curr && curr->val == x)
        		curr = curr->next;
        	temp->next = curr;
        }
        return head;
    }
};