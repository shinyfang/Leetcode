#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates2(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;
    	ListNode* result = new ListNode(-1);
    	ListNode* p = result;
    	bool flag = false;
    	//如果head->next == NULL,那么head->next->val会出错！！！！所以分开讨论！！！
    	while (head != NULL)
    	{
    		if (head->next == NULL)
    		{
    			if (flag)
    				break;
    			else
    			{
    				p->next = head;
    				p = p->next;
    			}
    		}
    		else
    		{
    			if (head->val == head->next->val)
    				flag = true;
    			else if (head->val != head->next->val && flag)
    				flag = false;
    			else
    			{
    				p->next = head;
    				p = p->next;
    			}
    		}
    		head = head->next;
    	}
    	p->next = NULL; //这里为了不让p指向的head跟着原来的head走，单独将p->next置为NULL，结束result链表
    	return result->next;
    }
};
/**int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	Solution s;
	ListNode* result = s.deleteDuplicates(head);
	while (result != NULL)
	{
		cout<<result->val<<" ";
		result = result->next;
	}
	return 0;
}
**/
