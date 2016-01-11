#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	//相当于看见每一层的最后一个root
    	vector<int> r;
    	if (root == NULL)
    		return r;
    	vector<TreeNode*> stk;
    	stk.push_back(root);
    	while (!stk.empty())
    	{
    		r.push_back(stk[stk.size()-1]->val);
    		vector<TreeNode*> temp;
    		for (int i = 0; i < stk.size(); i ++)
    		{
    			if (stk[i]->left != NULL)
    				temp.push_back(stk[i]->left);
    			if (stk[i]->right != NULL)
    				temp.push_back(stk[i]->right);
    		}
    		stk.clear();
    		stk = temp;
    	}
    	return r;
    }
};
