#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	//°ÑTreeÐòÁÐ»¯
    	string result = "";
    	serial(root,result);
    	result = result.substr(0,result.length()-1);
    	return result;
    }
    void serial(TreeNode* root, string& r)
    {
    	if (root == NULL)
    	{
    		r += "null,";
    		return;
    	}
    	serial(root->left,r);
    	serial(root->right,r);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
