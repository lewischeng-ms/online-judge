/**
 * Definition for singly-linked list.
  struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct compare {
    typedef bool result_type;
    typedef ListNode *first_argument_type;
    typedef ListNode *second_argument_type;
    bool operator()(ListNode *x, ListNode *y) const {
        return x->val < y->val;
    }
};
class Solution {
public:
    typedef multiset<ListNode *, compare> set_type;
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode head(0);
        ListNode *last = &head;
        set_type pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
            	pq.insert(lists[i]);
            	lists[i] = lists[i]->next;
            }
        }
        while (!pq.empty()) {
            set_type::iterator it = pq.begin();
            ListNode *curr = *it;
            pq.erase(it);
            if (curr->next)
                pq.insert(curr->next);
            curr->next = 0;
            last->next = curr;
            last = curr;
        }
        return head.next;
    }
};