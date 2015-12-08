#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if (root == NULL)
    		return false;
    	return pathSum(root,sum,0);
    }
    bool pathSum(TreeNode* root, int sum, int current)
    {
    	if (root->left == NULL && root->right == NULL)//µ½Ò¶½Úµã
    		return (current+root->val==sum?true:false);
    	bool left = false;
    	if (root->left != NULL)
    		left = pathSum(root->left,sum,current+root->val);
    	bool right = false;
    	if (root->right != NULL)
    		right = pathSum(root->right,sum,current+root->val);
    	if (left || right)
    		return true;
    	return false;
    }
};
