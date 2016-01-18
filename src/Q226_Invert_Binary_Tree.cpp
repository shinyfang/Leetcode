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
    TreeNode* invertTree(TreeNode* root) {
    	if (root == NULL)
    		return root;
    	cout<<root->val<<endl;
    	TreeNode* left = root->left;
    	TreeNode* right = root->right;
    	root->left = right;
    	root->right = left;
    	if (root->left != NULL)
    		invertTree(root->left);
    	if (root->right != NULL)
    		invertTree(root->right);
    	return root;
    }
};
