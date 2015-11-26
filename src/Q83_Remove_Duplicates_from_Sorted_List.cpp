#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;
    	ListNode* result = new ListNode(-1);
    	ListNode* p = result;
    	bool flag = false;//标记如果重复，是否压入了这个数字
    	while (head != NULL)
    	{
    		if (head->next == NULL)
    		{
    			if (!flag)
    			{
    				p->next = head;
    				p = p->next;
    			}
				break;
    		}
    		else
    		{
    			if (head->val == head->next->val && !flag)
    			{
    				p->next = head;
    				p = p->next;
    				flag = true;
    			}
    			else if (head->val != head->next->val && flag)
    			{
    				flag = false;
    			}
    			else if (head->val != head->next->val && !flag)
    			{
    				p->next = head;
    				p = p->next;
    			}
    		}
    		head = head->next;
    	}
    	p->next = NULL;
    	return result->next;
    }
};
