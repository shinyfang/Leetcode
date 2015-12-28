#include<iostream>
#include<deque>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/**
 * 超时！！！！！！！！！！！！！！！！
 * class Solution {
public:
    void reorderList(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return;
    	deque<ListNode*> list;
    	ListNode* p = head;
    	while (p != NULL)
    	{
    		list.push_back(p);
    		p = p->next;
    	}
    	ListNode* nhead = new ListNode(-1);
    	while(!list.empty())
    	{
    		ListNode* p1 = list[0];
    		nhead->next = p1;
    		nhead = nhead->next;
    		list.pop_front();
    		if (!list.empty())
    		{
    			p1->next = list[list.size()-1];
    			nhead = nhead->next;
    			list.pop_back();
    		}
    	}
    }
};
*/
class Solution {
public:
    void reorderList(ListNode* head) {
    	//从中间开始，后面的逆序，再合并两个链表
    	if (head == NULL || head->next == NULL || head->next->next == NULL)
    		return;
    	ListNode* pre = NULL;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while (slow && fast && fast->next)
    	{
    		pre = slow;
    		slow = slow->next;
    		if (fast->next == NULL || fast->next->next == NULL)
    			break;
    		fast = fast->next->next;
    	}
    	//cout<<slow->val<<" "<<fast->val<<endl;
    	slow = reverse(slow);
    	//cout<<slow->val<<endl;
    	ListNode* p = head;
    	while (p != NULL)//因为原来的slow已经指向了null
    	{
    		ListNode* temp = p->next;
    		p->next = slow;
    		if (slow->next == NULL)//如果slow->next==NULL下面就报错，且此时其实已经合并完成了，直接break即可
    			break;
    		slow = slow->next;
    		p = p->next;
    		p->next = temp;
    		p = p->next;
    	}
    	if (slow != NULL)
    		p = slow;
    }
    ListNode* reverse(ListNode* head)
    {
    	ListNode* pre = NULL;
    	ListNode* next = head->next;
    	while (head != NULL)
    	{
    		head->next = pre;
    		pre = head;
    		if (next == NULL)
    			break;
    		head = next;//不能head=NULL，所以要提前判断next是否是NULL
    		next = next->next;
    	}
    	return head;
    }
};
/**int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	Solution s;
	s.reorderList(head);
	cout<<head->val<<" "<<head->next->val<<" "<<head->next->next->val<<" "<<head->next->next->next->val;
	return 0;
}
**/
