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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > result;
		if (root == NULL)
			return result;
		deque<TreeNode*> que; //双向队列
		que.push_back(root);
		bool reverse = false;//加入第一行后，第二行要逆
		while (!que.empty()) {
			vector<int> temp1;
			deque<TreeNode*> temp2;
			if (reverse)
			{
				while(!que.empty())
				{
					TreeNode* temp3 = que.back();
					temp1.push_back(temp3->val);
					if (temp3->right != NULL)
						temp2.push_front(temp3->right);
					if (temp3->left != NULL)
						temp2.push_front(temp3->left);
					que.pop_back();
				}
				reverse = false;
			}
			else
			{
				while (!que.empty())
				{
					TreeNode* temp3 = que.front();
					temp1.push_back(temp3->val);
					if (temp3->left != NULL)
						temp2.push_back(temp3->left);
					if (temp3->right != NULL)
						temp2.push_back(temp3->right);
					que.pop_front();
				}
				reverse = true;
			}
			result.push_back(temp1);
			que = temp2;
		}
		return result;
	}
};
