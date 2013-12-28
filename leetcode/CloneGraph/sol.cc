/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *helper(UndirectedGraphNode *node,
		unordered_set<UndirectedGraphNode *> &visited,
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &mapper) {
		if (!node) return NULL;
		if (visited.count(node) > 0)
			return mapper[node];
		visited.insert(node);
    	UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    	mapper[node] = new_node;
    	for (auto i = node->neighbors.begin(); i != node->neighbors.end(); ++i) {
    		UndirectedGraphNode *successor = helper(*i, visited, mapper);
    		new_node->neighbors.push_back(successor);
    	}
    	return new_node;
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    	unordered_set<UndirectedGraphNode *> visited;
    	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mapper;
    	return helper(node, visited, mapper);
    }
};