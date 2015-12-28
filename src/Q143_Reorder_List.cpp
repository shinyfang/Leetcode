#include<iostream>
#include<deque>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/**
 * ��ʱ��������������������������������
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
    	//���м俪ʼ������������ٺϲ���������
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
    	while (p != NULL)//��Ϊԭ����slow�Ѿ�ָ����null
    	{
    		ListNode* temp = p->next;
    		p->next = slow;
    		if (slow->next == NULL)//���slow->next==NULL����ͱ����Ҵ�ʱ��ʵ�Ѿ��ϲ�����ˣ�ֱ��break����
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
    		head = next;//����head=NULL������Ҫ��ǰ�ж�next�Ƿ���NULL
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
