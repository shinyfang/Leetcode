#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;
    	ListNode* p1 = NULL;
    	ListNode* p2 = head;
    	while (p2->next != NULL)
    	{
    		ListNode* p3 = p2->next;
    		p2->next = p1;
    		p1 = p2;
    		p2 = p3;
    	}
    	p2->next = p1;
    	return p2;
    }
};
