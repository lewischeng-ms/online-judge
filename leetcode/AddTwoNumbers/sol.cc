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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode res(0);
        ListNode *last = &res;
        int c = 0;
        while (l1 || l2 || c) {
            int r = c;
            c = 0;
            if (l1) {
                r += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                r += l2->val;
                l2 = l2->next;
            }
            if (r > 9) {
                r -= 10;
                c = 1;
            }
            ListNode *tmp = new ListNode(r);
            last->next = tmp;
            last = tmp;
        }
        return res.next;
    }
};