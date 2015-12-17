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
//左子树所有的值都要小于所有左子树的跟，右子树同
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if (root == NULL || (root->left == NULL && root->right == NULL))
    		return true;
    	//return isValid(root,LONG_LONG_MIN,LONG_LONG_MAX);//要考虑出现了INT_MIN和INT_MAX的情况
    }
    bool isValid(TreeNode* root, long long min, long long max)
    {
    	if (root == NULL)
    		return true;
    	cout<<root->val<<" "<<min<<" "<<max<<endl;
    	if (root->val > min && root->val < max)
    		return (isValid(root->left, min, root->val)&&isValid(root->right, root->val, max));
    	else
    		return false;
    }
};
/**int main(){
	TreeNode* root = new TreeNode(-2147483648);
	root->right = new TreeNode(2147483647);
	//root->right->left = new TreeNode(1);
	Solution s;
	cout<<s.isValidBST(root);
	return 0;
}
**/
