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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        --m; --n;
        ListNode x(0);
        x.next = head;
        ListNode *p = &x;
        for (int i = 0; i < m; ++i)
            p = p->next;
        ListNode *q = p->next;
        p->next = 0;
        ListNode *last = q;
        for (int i = 0; i < n - m + 1; ++i) {
        	ListNode *next = q->next;
        	q->next = p->next;
        	p->next = q;
        	q = next;
        }
        last->next = q;
        return x.next;
    }
};