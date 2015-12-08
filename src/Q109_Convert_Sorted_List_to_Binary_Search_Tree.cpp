#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == NULL)
    		return NULL;
    	ListNode* end = head;
    	while (end->next != NULL)
    		end = end->next;
    	//cout<<head->val<<" "<<end->val<<endl;
    	return listBST(head,end);
    }
    TreeNode* listBST(ListNode* head, ListNode* end)
    {
    	if (head == end)
    	{
    		TreeNode* root = new TreeNode(head->val);
    		return root;
    	}
    	if (head->next == end)
    	{
    		TreeNode* root = new TreeNode(head->val);
    		root->right = new TreeNode(end->val);
    		return root;
    	}
    	ListNode* premid = head;
       	ListNode* mid = head->next;
       	ListNode* doublemid = mid->next;
       	while (doublemid != end)
       	{
       		premid = mid;
       		mid = mid->next;
       		doublemid = doublemid->next;
       		if (doublemid != end)
       			doublemid = doublemid->next;
       		else
       			break;
       	}
       	//ÖÐµãmid
       	TreeNode* root = new TreeNode(mid->val);
       	root->left = listBST(head,premid);
       	root->right = listBST(mid->next,end);
       	return root;
    }
};
