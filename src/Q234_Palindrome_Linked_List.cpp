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
    bool isPalindrome(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return true;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	bool odd = true;
    	while (fast->next != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next;
    		if (fast->next == NULL)
    			odd = false;
    		else
    			fast = fast->next;
    	}
    	ListNode* pre = slow;
    	ListNode* cur = slow->next;
    	pre->next = NULL;
    	while (cur != NULL)
    	{
    		ListNode* temp = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = temp;
    	}
    	if (odd)
    	{
    		while (head != fast)
    		{
    			if (head->val != fast->val)
    				return false;
    			head = head->next;
    			fast = fast->next;
    		}
    	}
    	else
    	{
    		while (head->next != fast)
    		{
    			if (head->val != fast->val)
    				return false;
    			head = head->next;
    			fast = fast->next;
    		}
    		if (head->val != fast->val)
    			return false;
    	}
    	return true;
    }
};
