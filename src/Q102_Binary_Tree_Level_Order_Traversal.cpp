#include<iostream>
#include<queue>
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
	vector<vector<int> > levelOrder(TreeNode* root) {
		vector<vector<int> > result;
		if (root == NULL)
			return result;
		queue<TreeNode*> que;//queue只能是元素类型，
		que.push(root);
		while (!que.empty()) {
			vector<int> temp1;
			queue<TreeNode*> temp2;
			while (!que.empty()) {
				TreeNode* temp3 = que.front();
				cout<<temp3->val<<endl;
				temp1.push_back(temp3->val);
				if (temp3->left != NULL)
					temp2.push(temp3->left);
				if (temp3->right != NULL)
					temp2.push(temp3->right);
				que.pop();
			}
			result.push_back(temp1);
			que = temp2;
		}
		return result;
	}
};
/**int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	vector<vector<int> > result = s.levelOrder(root);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
**/
