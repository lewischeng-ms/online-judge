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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head;
        ListNode *prev = 0;
        int len = 0;
        while (p) {
            ++len;
            prev = p;
        	p = p->next;
        }
        ListNode *last = prev;
        if (len < 1) return NULL;
        k %= len;
        if (k < 1) return head;
        int m = len  - k;
        p = head;
        prev = 0;
        while (m-- > 0) {
        	prev = p;
        	p = p->next;
        }
        prev->next = 0;
        last->next = head;
        return p;
    }
};