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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
    	vector<vector<int> > result;
    	if (root == NULL)
    		return result;
    	vector<TreeNode*> p;
    	pathS(result,root,p,sum,0);
    	return result;
    }
    void pathS(vector<vector<int> >& result, TreeNode* root, vector<TreeNode*>& path, int sum, int current)
    {
    	path.push_back(root);
    	current += root->val;
    	if (root->left == NULL && root->right == NULL)
    	{
    		if (current == sum)
    		{
    			vector<int> temp;
    			for (int i = 0; i < path.size(); i++)
    			{
    				temp.push_back(path[i]->val);
    			}
    			result.push_back(temp);
    		}
    	}
    	if (root->left != NULL)
    		pathS(result,root->left,path,sum,current);
    	if (root->right != NULL)
    		pathS(result,root->right,path,sum,current);
    	path.pop_back();//用引用，每次找到了叶节点后弹出，找另一个叶节点
    }
};
