#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	if (head == NULL)
    		return head;
    	ListNode* nhead = new ListNode(-1);
    	ListNode* p = nhead;
    	while (head != NULL)
    	{
    		if (head->val == val)
    			p->next = head->next;
    		else
    		{
    			p->next = head;
    			p = p->next;
    		}
    		if (head->next == NULL)
    			break;
    		head = head->next;
    	}
    	return nhead->next;
    }
};
/**int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	Solution s;
	ListNode* nhead = s.removeElements(head,1);
	cout<<nhead->val;
	return 0;
}
**/
