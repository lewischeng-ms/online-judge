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
        ListNode n(0);
        ListNode *curr = head;
        ListNode *last = &n;
        while (curr) {
            int x = curr->val;
            ListNode *t = curr;
            curr = curr->next;
            int c = 1;
            while (curr && curr->val == x) {
                ++c;
                curr = curr->next;
            }
            if (c == 1) {
                t->next = 0;
                last->next = t;
                last = t;
            }
        }
        return n.next;
    }
};