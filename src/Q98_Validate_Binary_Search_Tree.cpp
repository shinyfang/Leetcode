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
//���������е�ֵ��ҪС�������������ĸ���������ͬ
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if (root == NULL || (root->left == NULL && root->right == NULL))
    		return true;
    	return isValid(root,LONG_LONG_MIN,LONG_LONG_MAX);//Ҫ���ǳ�����INT_MIN��INT_MAX�����
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
