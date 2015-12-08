#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
    	if (inorder.size() == 0)
    		return NULL;
    	return buildT2(inorder,0,inorder.size()-1,postorder,postorder.size()-1);
    }
    TreeNode* buildT2(vector<int>& inorder, int ibegin, int iend, vector<int>& postorder, int pend)
    {
    	TreeNode* root = new TreeNode(postorder[pend]);
    	int r = ibegin;
    	for (; r <= iend; r++)
    	{
    		if (inorder[r] == postorder[pend])
    			break;
    	}
    	if (r > ibegin)
    		root->left = buildT2(inorder,ibegin,r-1,postorder,pend-(iend-r)-1);
    	if (r < iend)
    		root->right = buildT2(inorder,r+1,iend,postorder,pend-1);
    	return root;
    }
};
