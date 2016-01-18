#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//����������������ʽ�������n�㣬��ô�ڵ�����Ϊ2^n-1
//�����ж���������Ƿ���ȣ������ж��Ƿ�����������
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
    		return (1<<left)-1;//-�����ȼ���<<�ߣ�����Ҫ������
    	return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
