/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	typedef map<RandomListNode *, RandomListNode *> map_type;
	RandomListNode *helper(RandomListNode *head, map_type &mapper) {
		if (!head)
			return NULL;
		if (mapper[head] != NULL)
			return mapper[head];
		RandomListNode *new_head = new RandomListNode(head->label);
		mapper[head] = new_head;
		new_head->next = helper(head->next, mapper);
		new_head->random = helper(head->random, mapper);
		return new_head;
	}

    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map_type mapper;
        return helper(head, mapper);
    }
};