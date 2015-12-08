#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	if (depth(root) == -1)
    		return false;
    	return true;
    }
    int depth(TreeNode* root)
    {
    	if (root == NULL)
    		return 0;
    	int left = depth(root->left);
    	int right = depth(root->right);
    	if (left == -1 || right == -1 || abs(left-right)>1) //每到一个节点判断，如果不符合直接返回
    		return -1;
    	return (left>right?left:right)+1;//符合的话返回当前的最大深度
    }
};
