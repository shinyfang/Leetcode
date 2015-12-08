#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
    	if (root == NULL)
    		return;
    	//cout<<root->val<<endl;
    	if (root->left == NULL && root->right == NULL)
    		return;
    	flatten(root->left);
    	flatten(root->right);
    	if (root->left == NULL)
    		return;
    	if (root->right == NULL)
    	{
    		root->right = root->left;
    		root->left = NULL;
    		return;
    	}
    	TreeNode* right = root->right;
    	root->right = root->left;
    	root->left = 0;
    	TreeNode* p = root->right;
    	while (p->right != NULL)
    		p = p->right;
    	p->right = right;
    }
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	//root->right = new TreeNode(3);
	Solution s;
	s.flatten(root);
	cout<<root->val<<" "<<root->right->val<<endl;
	return 0;
}
**/
