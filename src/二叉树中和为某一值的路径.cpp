#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution{
public:
	vector<vector<int> > FindPath(TreeNode* root, int sum)
	{
		vector<vector<int> > result;
		if (root == NULL)
			return result;
		vector<TreeNode*> stk;
		FindP(result,stk,root,sum,0);
		return result;
	}
	void FindP(vector<vector<int> >& result, vector<TreeNode*> stk, TreeNode* root, int sum, int count)
	{
		count += root->val;
		stk.push_back(root);
		bool isLeaf = root->left == NULL && root->right == NULL;//判断是否是叶节点
		if (isLeaf && count == sum)
		{
			vector<int> res;
			for (int i = 0; i < stk.size(); i++)//因为要遍历找val,所以只能用vector
				res.push_back(stk[i]->val);
			result.push_back(res);
		}
		if (root->left != NULL)
			FindP(result,stk,root->left,sum,count);
		if (root->right != NULL)
			FindP(result,stk,root->right,sum,count);
		stk.pop_back();
	}
};
/**int main(){
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	Solution s;
	int sum = 22;
	vector<vector<int> > result = s.FindPath(root, sum);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}
**/
