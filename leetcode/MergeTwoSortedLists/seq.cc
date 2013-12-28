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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode head(0);
        ListNode *last = &head;
        while (l1 && l2) {
            ListNode *next;
            if (l1->val < l2->val) {
                next = l1->next;
                last->next = l1;
                last = l1;
                l1 = next;
            } else {
                next = l2->next;
                last->next = l2;
                last = l2;
                l2 = next;
            }
        }
        if (l1)
            last->next = l1;
        else
            last->next = l2;
        return head.next;
    }
};