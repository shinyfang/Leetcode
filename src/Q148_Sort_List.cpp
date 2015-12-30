#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while (fast->next != NULL && fast->next->next != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	ListNode* head2 = slow->next;
    	//cout<<slow->val<<" "<<head2->val<<endl;
    	slow->next = NULL;//直接把next置NULL即可
    	ListNode* left = sortList(head);
    	ListNode* right = sortList(head2);
    	ListNode* nhead = new ListNode(-1);
    	ListNode* p = nhead;
    	while (left != NULL && right != NULL)
    	{
    		if (left->val > right->val)
    		{
    			p->next = right;
    			right = right->next;
    		}
    		else
    		{
    			p->next = left;
    			left = left->next;
    		}
    		p = p->next;
    	}
    	if (left != NULL)
    		p->next = left;
    	if (right != NULL)
    		p->next = right;
    	return nhead->next;
    }
};
/**int main(){
	ListNode* head = new ListNode(3);
	head->next = new ListNode(4);
	head->next->next = new ListNode(1);
	//head->next->next->next = new ListNode(1);
	Solution s;
	ListNode* nhead = s.sortList(head);
	cout<<nhead->val<<" "<<nhead->next->val<<" "<<nhead->next->next->val;//<<" "<<nhead->next->next->next->val;
	return 0;
}
**/
