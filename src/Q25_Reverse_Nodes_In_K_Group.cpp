#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (head == NULL || head->next == NULL || k <= 1)
    		return head;
    	ListNode* result = new ListNode(-1);
    	ListNode* p1 = head;
    	result->next = head;
    	ListNode* p = result;
    	while (1)
    	{
    		if (p1 == NULL)
    			return result->next;
    		ListNode* p2 = p1;
    		int len = k-1;
    		while (len)
    		{
    			if (p2->next == NULL)
    				return result->next;
    			p2 = p2->next;
    			len--;
    		}
    		p->next = p2;
    		if (k == 2)//不用p3
    		{
    			cout<<"p1:"<<p1->val<<" p2:"<<p2->val<<endl;
    			p1->next = p2->next;
    			p2->next = p1;
    			p = p1;
    			p1 = p1->next;
    		}
    		else
    		{
    			ListNode* temp = p1;
    			ListNode* p3 = p1->next;//next要变的节点
    			ListNode* p4 = p3->next;//要变的节点的next
    			while (p4 != p2)
    			{
    				p3->next = p1;
    				p1 = p3;
    				p3 = p4;
    				p4 = p4->next;
    			}
    			temp->next = p2->next;//记录下次循环的p1
    			p3->next = p1;
    			p2->next = p3;
    			p = temp;
    			p1 = temp->next;
    		}
    	}
	}
};
/**int main(){
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	int k = 5;
	ListNode* result = s.reverseKGroup(head,k);
	cout<<result->val<<" "<<result->next->val<<" "<<result->next->next->val<<endl;
	//<<" "<<result->next->next->val<<" "<<result->next->next->next->val<<endl;
	return 0;
}
**/
