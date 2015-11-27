#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
        	return head;
        ListNode* min = new ListNode(-1);
        ListNode* p1 = min;
        ListNode* max = new ListNode(-1);
        ListNode* p2 = max;
        while (head != NULL)
        {
        	if (head->val < x)
        	{
        		p1->next = head;
        		p1 = p1->next;
        	}
        	else
        	{
        		p2->next = head;
        		p2 = p2->next;
        	}
        	head = head->next;
        	p1->next = NULL; //注意这里要先移动p，再对p1->next和p2->next置空
        	p2->next = NULL;
        }
        if (min->next == NULL)
        	return max->next;
        if (max->next == NULL)
        	return min->next;
        p1->next = max->next;
        return min->next;
    }
};
