#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *out = new ListNode(0);
    	ListNode *head = out;
    	int flag = 0;
    	while(l1 != NULL || l2 != NULL){
    		if(l1 == NULL && l2 != NULL){
    			out->next = new ListNode((l2->val+flag)%10);
    			out = out->next;
    			if (l2->val+flag >= 10)
    				flag = 1;
    			else
    				flag = 0;
    			l2 = l2->next;
    		}
    		else if (l1 != NULL && l2 == NULL){
    			out->next = new ListNode((l1->val+flag)%10);
    			out = out->next;
    			if ((l1->val+flag) >= 10)
    				flag = 1;
    			else
    				flag = 0;
    			l1 = l1->next;
    		}
    		else{
    			out->next = new ListNode((l1->val+l2->val+flag)%10);
    			out = out->next;
    			if ((l1->val+l2->val+flag) >= 10)
    				flag = 1;
    			else
    				flag = 0;
    			l1 = l1->next;
    			l2 = l2->next;
    		}
    	}
    	if(flag == 1)
    		out->next = new ListNode(1);
    	return head->next;
    }
};
int main(){
	ListNode *l1 = new ListNode(5);
	//l1->next = new ListNode(8);
	//l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	//l2->next = new ListNode(6);
	//l2->next->next = new ListNode(4);
	Solution s;
	ListNode *out = s.addTwoNumbers(l1,l2);
	cout<<out->val<<out->next->val;
	return 0;
}
