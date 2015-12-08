#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = 0;
        if (root == NULL)
        	return max;
        stack<TreeNode*> stk;
        max = mDepth(root,stk, 0,max);
        return max;
    }
    int mDepth(TreeNode* root, stack<TreeNode*> stk, int depth, int max)
    {
    	stk.push(root);
    	depth += 1;
    	max = depth>max?depth:max;
    	if (root->left != NULL)
    		max = mDepth(root->left, stk, depth, max);
    	if (root->right != NULL)
    		max = mDepth(root->right, stk, depth, max);
		stk.pop();
    	return max;
    }
};
**/

class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	int left = maxDepth(root->left);
    	int right = maxDepth(root->right);
    	return (left>right?left:right)+1;
    }
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	Solution s;
	cout<<s.maxDepth(root);
	return 0;
}
**/
