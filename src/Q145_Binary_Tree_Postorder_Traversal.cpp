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
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> result;
    	if (root == NULL)
    		return result;
    	stack<TreeNode*> stk;
    	stk.push(root);
    	while (!stk.empty())
    	{
    		TreeNode* top = stk.top();
    		if (top->left == NULL && top->right == NULL)
    		{
    			result.push_back(top->val);
    			stk.pop();
    		}
    		else if (top->left != NULL)
    		{
    			stk.push(top->left);
    			top->left = NULL;
    		}
    		else
    		{
    			stk.push(top->right);
    			top->right = NULL;
    		}
    	}
    	return result;
    }
};
/**int main(){
	TreeNode* head  = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	Solution s;
	vector<int> result = s.postorderTraversal(head);
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";
	return 0;
}
**/
