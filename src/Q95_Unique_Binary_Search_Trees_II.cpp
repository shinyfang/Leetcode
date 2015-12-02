#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        //DFS,left=null||right=null
    	vector<TreeNode*> result;
    	if (n < 1)
    		return result;
    	vector<int> tree;
    	for (int i = 0; i < n; i++)
    		tree.push_back(i+1);
    	TreeNode* res;
    	generate(tree,0,tree.size()-1,result,res);
    	return result;
    }
    void generate(vector<int> tree, int begin, int end, vector<TreeNode*>& result, TreeNode*& res)
    {
    	if (begin < 0 || end >= tree.size())
    		return;
    	for (int i = begin; i <= end; i++)
    	{
    		res = new TreeNode(tree[i]);
    		TreeNode* p = res;
    		if (i != begin)
    		{
    			p = res->left;
    			generate(tree,0,i-1,result,p);
    		}
    		p = res->right;
    		generate(tree,i+1,end,result,p);
    	}
    }
};
int main(){
	int n = 8;
	Solution s;
	vector<TreeNode*> result = s.generateTrees(n);
	return 0;
}
