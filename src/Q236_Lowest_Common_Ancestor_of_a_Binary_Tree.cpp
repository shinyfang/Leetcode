#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (root == NULL)
    		return root;
    	if (p == NULL || q == NULL)
    		return p==NULL?q:p;
    	return lowestC(root,p,q,false,false,NULL);
    }
    TreeNode* lowestC(TreeNode* root, TreeNode* p, TreeNode* q, bool findp, bool findq, TreeNode* res)
    {
    	if (root->val == p->val && root->val == q->val)
    		return root;
    	else if (root->val == p->val)
    	{

    	}
    }
};
