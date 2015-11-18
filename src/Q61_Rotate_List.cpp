#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head == NULL)
    		return head;
    	int len = 0;
    	ListNode* temp = head;
    	while (temp != NULL)
    	{
    		len++;
    		temp = temp->next;
    	}
    	k = k%len;
    	if (k == 0)
    		return head;
    	//p1新链表的尾部，指向NULL
    	//p2新链表的头部
    	//p3新链表指向原链表头部的地方
    	ListNode* p1 = head;
    	int num1 = len-k-1;
    	while (num1--)
    	{
    		p1 = p1->next;
    	}
    	ListNode* p2 = p1->next;
    	ListNode* p3 = p2;
    	while(p3->next != NULL)
    		p3 = p3->next;
    	p1->next = NULL;
    	p3->next = head;
    	return p2;
    }
};
/**int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution s;
	int k = 2;
	ListNode* result = s.rotateRight(head,k);
	while (result != NULL)
	{
		cout<<result->val<<" ";
		result = result->next;
	}
	return 0;
}
**/
