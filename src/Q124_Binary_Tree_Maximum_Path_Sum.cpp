#include<iostream>
#include<deque>
#include<vector>
#include<climits>
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
	int ans;//�����ȫ������ֵ
    int maxPathSum(TreeNode* root) {
    	//ÿ�ζ���ĳ���ڵ���Ϊroot�������������������������������ۼ�ֵ�����
    	if (root == NULL)
    		return 0;
    	ans = root->val;//��ʼ��
    	maxPath(root);
    	return ans;
    }
    int maxPath(TreeNode* root)//���ﷵ��root+left����root+right����root�е����ֵ������һ��rootʹ��
    {
    	int max = root->val;
    	int left = 0;
    	if (root->left != NULL)
    		left = maxPath(root->left);
    	int right = 0;
    	if (root->right != NULL)
    		right = maxPath(root->right);
    	if (left > 0)
    		max += left;
    	if (right > 0)
    		max += right;
    	ans = max>ans?max:ans;
    	int lmax = root->val;
    	lmax = (root->val+left)>lmax?(root->val+left):lmax;
    	lmax = (root->val+right)>lmax?(root->val+right):lmax;
    	return lmax;
    }
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	cout<<s.maxPathSum(root);
	return 0;
}
**/
