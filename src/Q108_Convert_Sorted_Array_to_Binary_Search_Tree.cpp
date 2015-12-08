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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if (nums.size() == 0)
    		return NULL;
    	return rootBST(nums,0,nums.size()-1);
    }
    TreeNode* rootBST(vector<int>& nums, int i, int j)
    {
    	if (i == j)
    		return new TreeNode(nums[i]);
    	int mid = (i + j) / 2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	if (mid > i)
    		root->left = rootBST(nums,i,mid-1);
    	if (mid < j)
    		root->right = rootBST(nums,mid+1,j);
    	return root;
    }
};
