#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
    	if (n < 1) //若n=0，直接返回，不需要NULL
    	{
    	    vector<TreeNode*> result;
    	    return result;
    	}
    	return generateT(1,n);//返回1-n之间组成的树的vector
    }
    vector<TreeNode*> generateT(int begin, int end)
	{
    	vector<TreeNode*> result;
    	if (begin > end)
    	{
    		result.push_back(NULL);
    		return result;
    	}
    	for (int i = begin; i <= end; i++)
    	{
    		vector<TreeNode*> left = generateT(begin,i-1);
    		vector<TreeNode*> right = generateT(i+1,end);
    		for (int l = 0; l < left.size(); l++)
    		{
    			for (int r = 0; r < right.size(); r++)
    			{
    			    TreeNode* root = new TreeNode(i);
    				root->left = left[l];
    				root->right = right[r];
    				result.push_back(root);
    			}

    		}
    	}
    	return result;
	}
};
