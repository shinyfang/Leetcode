#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	stack<TreeNode*> stk;
    int kthSmallest(TreeNode* root, int k) {
    	pushStack(root);
    	while (k != 1)
    	{
    		TreeNode* top = stk.top();
    		stk.pop();
    		if (top->right != NULL)
    			pushStack(top->right);
    		k --;
    	}
    	return stk.top()->val;
    }
    void pushStack(TreeNode* root)
    {
    	while (root != NULL)
    	{
    		stk.push(root);
    		root = root->left;
    	}
    }
};
/**int main(){
	TreeNode* root = new TreeNode(50);
	root->left = new TreeNode(20);
	root->right = new TreeNode(60);
	root->left->left = new TreeNode(15);
	root->left->left->right = new TreeNode(18);
	root->left->left->right->left = new TreeNode(17);
	root->left->left->right->right = new TreeNode(19);
	root->right->right = new TreeNode(70);
	Solution s;
	cout<<s.kthSmallest(root,6);
	return 0;
}
**/
