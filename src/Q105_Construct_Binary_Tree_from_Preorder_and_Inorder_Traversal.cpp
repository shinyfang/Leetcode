#include<iostream>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	//&保证了每次调动的时候不用新建vector，而是直接引用
    	if (preorder.size() == 0)
    		return NULL;
    	return buildT(preorder,0,inorder,0,inorder.size()-1);
    }
    TreeNode* buildT(vector<int>& preorder, int pbegin, vector<int>& inorder, int ibegin, int iend)
    {
    	//cout<<preorder[pbegin]<<endl;
    	TreeNode* root = new TreeNode(preorder[pbegin]);
    	int l = ibegin;
    	for (; l <= iend; l++)
    	{
    		if (inorder[l] == preorder[pbegin])
    			break;
    	}
    	if (l > ibegin)
    		root->left = buildT(preorder, pbegin+1, inorder, ibegin, l-1);
    	if (l < iend)
    		root->right = buildT(preorder, pbegin+l-ibegin+1, inorder, l+1, iend);
    	return root;
    }
};
/**int main(){
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(7);
	preorder.push_back(3);
	preorder.push_back(5);
	preorder.push_back(6);
	preorder.push_back(8);
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(7);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(5);
	inorder.push_back(3);
	inorder.push_back(8);
	inorder.push_back(6);
	Solution s;
	TreeNode* root = s.buildTree(preorder,inorder);
	cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<" "<<root->left->left->val<<" "<<root->right->left->val<<" "<<root->right->right->val<<" "<<root->left->left->right->val<<" "<<root->right->right->left->val<<endl;
	return 0;
}
**/
