#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;
    	ListNode* nhead = new ListNode(-1);
    	while (head != NULL)
    	{
    		ListNode* p = nhead;
    		while (p->next != NULL && p->next->val < head->val)
    			p = p->next;
    		ListNode* temp = head->next;
    		head->next = p->next;
    		p->next = head;
    		head = temp;
    	}
    	return nhead->next;
    }
};
/**int main(){
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	Solution s;
	ListNode* nhead = s.insertionSortList(head);
	cout<<nhead->val<<" "<<nhead->next->val<<" "<<nhead->next->next->val<<endl;
	return 0;
}
**/
