#include<iostream>
#include<vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> result;
    	if (root == NULL)
    		return result;
    	TreeNode* p = root;
    	stack<TreeNode*> stk;//压入整个指针
    	while (p != NULL || !stk.empty())
    	{
    		if (p != NULL)
    		{
    			stk.push(p);
    			p = p->left;
    		}
    		else
    		{
    			p = stk.top();
    			stk.pop();
    			result.push_back(p->val);
    			p = p->right;
    		}
    	}
    	return result;
    }
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->left->right = new TreeNode(5);
	Solution s;
	vector<int> result = s.inorderTraversal(root);
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";
	return 0;
}
**/
