#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
	int result;
    int sumNumbers(TreeNode* root) {
    	result = 0;
    	if (root == NULL)
    		return result;
    	vector<TreeNode*> tree;
    	vector<int> res;
    	sumN(root,tree,res);
    	return result;
    }
    void sumN(TreeNode* root, vector<TreeNode*>& tree, vector<int>& res)
    {
    	tree.push_back(root);
    	res.push_back(root->val);
    	if (root->left == NULL && root->right == NULL)
    	{
    		int sum = res[0];
    		for (int i = 1; i < res.size(); i++)
    			sum = sum*10 + res[i];
    		result += sum;
    	}
    	if (root->left != NULL)
    		sumN(root->left,tree,res);
    	if (root->right != NULL)
    		sumN(root->right,tree,res);
    	tree.pop_back();
    	res.pop_back();
    }
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	cout<<s.sumNumbers(root);
	return 0;
}
**/
