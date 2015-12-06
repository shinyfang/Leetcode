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
	bool isSymmetric(TreeNode* root) {
		//在原树上判断即可
		if (root == NULL)
			return true;
		return isSym(root->left,root->right);
	}
	bool isSym(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == NULL && p2 == NULL)
			return true;
		if (!p1 || !p2)
			return false;
		if (p1->val == p2->val)
			return isSym(p1->left,p2->right)&isSym(p1->right,p2->left);
		else
			return false;
	}
};
