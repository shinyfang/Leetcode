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
    void recoverTree(TreeNode* root) {
        if (root == NULL)
        	return;
        vector<TreeNode*> inorder;
        InOrder(root,inorder);
        //for (int i = 0; i < inorder.size(); i++)
        //	cout<<inorder[i]->val<<" ";
        if (inorder.size() < 2)
        	return;
        TreeNode* swap1 = inorder[0];
        TreeNode* swap2 = inorder[inorder.size()-1];
        for (int i = 0; i < inorder.size()-1; i++)
        {
        	if (inorder[i]->val > inorder[i+1]->val)
        	{
        		swap1 = inorder[i];
        		break;
        	}
        }
        for (int i = inorder.size()-1; i > 0; i--)
        {
        	if (inorder[i]->val < inorder[i-1]->val)
        	{
        		swap2 = inorder[i];
        		break;
        	}
        }
        //cout<<swap1->val<<" "<<swap2->val<<endl;
        swap(swap1->val,swap2->val);//交换的是值，不是节点
        //cout<<swap1->val<<" "<<swap2->val<<endl;
    }
    void InOrder(TreeNode* root, vector<TreeNode*>& inorder)//存节点，不能存值
    {
    	if (root == NULL)
    		return;
    	InOrder(root->left, inorder);
    	inorder.push_back(root);
    	InOrder(root->right, inorder);
    }
};
/**int main(){
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	//root->right = new TreeNode(3);
	//root->right->left = new TreeNode(4);
	//root->right->left->right = new TreeNode(5);
	Solution s;
	s.recoverTree(root);
	return 0;
}
**/
