#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if (headA == NULL || headB == NULL)
    		return NULL;
    	int lenA = 1;
    	ListNode* p = headA;
    	while (p->next != NULL)
    	{
    		lenA ++;
    		p = p->next;
    	}
    	int lenB = 1;
    	p = headB;
    	while (p->next != NULL)
    	{
    		lenB ++;
    		p = p->next;
    	}
    	if (lenA > lenB)
    	{
    		int temp = lenA - lenB;
    		while (temp--)
    			headA = headA->next;
    	}
    	else if (lenA < lenB)
    	{
    		int temp = lenB - lenA;
    		while (temp--)
    			headB = headB->next;
    	}
    	while (headA != NULL)
    	{
    		if (headA == headB)
    			return headA;
    		if (headA->next != NULL)
    		{
				headA = headA->next;
				headB = headB->next;
    		}
    		else
    			break;
    	}
    	return NULL;
    }
};
