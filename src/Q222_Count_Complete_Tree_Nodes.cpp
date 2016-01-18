#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//利用满二叉树的形式，如果有n层，那么节点总数为2^n-1
//不断判断左右深度是否相等，可以判断是否是满二叉树
class Solution {
public:
    int countNodes(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	int left = 1;
    	TreeNode* p = root;
    	while (p->left != NULL)
    	{
    		left ++;
    		p = p->left;
    	}
    	int right = 1;
    	p = root;
    	while (p->right != NULL)
    	{
    		right ++;
    		p = p->right;
    	}
    	if (left == right)
    		return (1<<left)-1;//-的优先级比<<高，所以要用括号
    	return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
