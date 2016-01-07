#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//非递归的中序遍历
class BSTIterator {
public:
	stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
    	while (!stk.empty())//主函数里因为每次的root都会换，所以要清空
    		stk.pop();
    	while (root != NULL)
    	{
    		stk.push(root);
    		root = root->left;
    	}
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
    	if (stk.empty())
    		return false;
    	return true;
    }
    /** @return the next smallest number */
    int next() {
    	TreeNode* next = stk.top();
    	stk.pop();
    	if (next->right != NULL)
    	{
    		TreeNode* p = next->right;
    		while (p != NULL)
    		{
    			stk.push(p);
    			p = p->left;
    		}
    	}
    	return next->val;
    }
};
