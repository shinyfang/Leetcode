#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (head == NULL || head->next == NULL || m == n)
    		return head;
    	ListNode* result = new ListNode(-1);
    	ListNode* p1 = head;//指向m前一个数
    	ListNode* p2 = head;//指向n
    	int begin = m;
    	if (m != 1) //要判断m的值，否则当m < 0时 while会出错
    	{
    		m --;
    		while (-- m)
    		{
    			p1 = p1->next;
    		}
    	}
    	while (--n)
    	{
    		p2 = p2->next;
    	}
    	if (begin == 1)
    		result->next = p2;//首
    	else
    	{
    		result->next = head;
    		ListNode* temp = p1;
    		p1 = p1->next;
    		temp->next = p2;
    	}
    	ListNode* s1 = p1->next;
    	p1->next = p2->next;//尾
    	while (s1 != p2)
    	{
    		ListNode* temp = s1->next;
    		s1->next = p1;
    		p1 = s1;
    		s1 = temp;
    	}
    	p2->next = p1;
    	return result->next;
    }
};
/**int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	int m = 1;
	int n = 2;
	Solution s;
	ListNode* result = s.reverseBetween(head,m,n);
	return 0;
}
**/
