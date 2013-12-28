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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *first = head;
        while (n-- > 0) {
            if (!first) return head;
            first = first->next;
        }
        
        ListNode *previous = 0;
        ListNode *second = head;
        while (first) {
            previous = second;
            first = first->next;
            second = second->next;
        }
        
        if (!previous)
            head = second->next;
        else
            previous->next = second->next;
        
        return head;
    }
};