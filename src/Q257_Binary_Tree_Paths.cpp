#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<string> result;
	//����||�������ľ�û���յ㣬���Ҷ�û�����յ�
    vector<string> binaryTreePaths(TreeNode* root) {
    	if (root == NULL)
    		return result;
    	string res;
    	bTree(root,res);
    	return result;
    }
    void bTree(TreeNode* root, string res)
    {
    	res += int2str(root->val);
    	if (root->left == NULL && root->right == NULL)
    		result.push_back(res);
    	if (root->left != NULL)
    		bTree(root->left,res+"->");
    	if (root->right != NULL)
    		bTree(root->right,res+"->");
    }
    string int2str(int val)
    {
    	stringstream ss;
    	ss<<val;
    	string r;
    	ss>>r;
    	return r;
    }
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	Solution s;
	vector<string> result = s.binaryTreePaths(root);
	for (int i = 0; i < result.size(); i ++)
	{
		for (int j = 0; j < result[i].length(); j ++)
			cout<<result[i][j];
		cout<<endl;
	}
	return 0;
}
**/
