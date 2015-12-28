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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> result;
    	if (root == NULL)
    		return result;
    	stack<TreeNode*> node;
    	node.push(root);
    	TreeNode* p = root;
    	while (!node.empty())
    	{
    		TreeNode* top = node.top();
    		result.push_back(top->val);
    		node.pop();
    		if (top->right != NULL)
    			node.push(top->right);
    		if (top->left != NULL)
    			node.push(top->left);
    	}
    	return result;
    }
};
