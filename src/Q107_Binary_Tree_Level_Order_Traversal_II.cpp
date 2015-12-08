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
	vector<vector<int> > levelOrderBottom(TreeNode* root) {
		vector<vector<int> > result;
		if (root == NULL)
			return result;
		queue<TreeNode*> que; //queue只能是元素类型，
		que.push(root);
		while (!que.empty()) {
			vector<int> temp1;
			queue<TreeNode*> temp2;
			while (!que.empty()) {
				TreeNode* temp3 = que.front();
				cout << temp3->val << endl;
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
		reverse(result.begin(),result.end());
		return result;
	}
};
