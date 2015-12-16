#include<iostream>
#include<vector>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
/**class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == NULL)
    		return NULL;
    	//判断最终是否已经全部遍历完，需要存储所有的节点并且可以查找的，DFS
    	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> copy;
    	//所有节点都存在copy中，是复制的节点，并且每个节点都有neighbors指向其他节点
    	dfs(node,copy);
    	return copy[node];
    }
    UndirectedGraphNode * dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& copy)
    {
    	if (copy.find(node) != copy.end())
    		return copy[node];//如果已经存入了就直接给neighbor
    	UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
    	copy[node] = newnode;
    	for (int i = 0; i < node->neighbors.size(); i++)
    		newnode->neighbors.push_back(dfs(node->neighbors[i],copy));
    	return newnode;
    }
};
**/
