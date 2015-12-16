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
    	//�ж������Ƿ��Ѿ�ȫ�������꣬��Ҫ�洢���еĽڵ㲢�ҿ��Բ��ҵģ�DFS
    	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> copy;
    	//���нڵ㶼����copy�У��Ǹ��ƵĽڵ㣬����ÿ���ڵ㶼��neighborsָ�������ڵ�
    	dfs(node,copy);
    	return copy[node];
    }
    UndirectedGraphNode * dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& copy)
    {
    	if (copy.find(node) != copy.end())
    		return copy[node];//����Ѿ������˾�ֱ�Ӹ�neighbor
    	UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
    	copy[node] = newnode;
    	for (int i = 0; i < node->neighbors.size(); i++)
    		newnode->neighbors.push_back(dfs(node->neighbors[i],copy));
    	return newnode;
    }
};
**/
