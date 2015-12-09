#include<iostream>
#include<vector>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == NULL || root->left == NULL)//完全二叉树，如果左儿子没有就是叶节点
    		return;
    	vector<TreeLinkNode*> tree;
    	tree.push_back(root->left);
    	tree.push_back(root->right);
    	while (!tree.empty())
    	{
    		int len = tree.size();
    		cout<<len<<endl;
    		for (int i = 0; i < len; i++)
    		{
    			if (i < len - 1)
    				tree[i]->next = tree[i+1];
    			if (tree[i]->left != NULL)
    			{
    				tree.push_back(tree[i]->left);
    				tree.push_back(tree[i]->right);
    			}
    		}
    		tree.erase(tree.begin(),tree.begin()+len);
    	}
    }
};
/**int main(){
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	Solution s;
	s.connect(root);
	cout<<root->left->next;
	return 0;
}
**/
