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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p = head;
        ListNode *q = head;
        while (q != NULL) {
            p = p->next;
            q = q->next ? q->next->next : NULL;
            if (p == q && p != NULL)
                return true;
        }
        return false;
    }
};