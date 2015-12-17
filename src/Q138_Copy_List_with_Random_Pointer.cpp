#include<iostream>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	//深拷贝？？？
    	if (head == NULL)
    		return head;
    	RandomListNode* p = head;
    	while (p != NULL)
    	{
    		RandomListNode* temp = new RandomListNode(p->label);
    		temp->next = p->next;
    		p->next = temp;
    		p = temp->next;
    	}
    	p = head;
    	while (p != NULL)
    	{
    		if (p->random == NULL)
    			p->next->random = NULL;
    		else
    			p->next->random = p->random->next;
    		p = p->next->next;
    	}
    	RandomListNode nhead(-1);//这里要加个头，否则在下面的while中容易出现将指针赋给null的next的情况
    	RandomListNode* np = &nhead;
    	p = head;
    	while (p != NULL)
    	{
    		np->next = p->next;
    		np = np->next;
    		p->next = np->next;
    		p = p->next;
    	}
    	return nhead.next;
    }
};
/**int main(){
	RandomListNode * head = new RandomListNode(1);
	//head->next = new RandomListNode(2);
	//head->next->next = new RandomListNode(3);
	Solution s;
	s.copyRandomList(head);
	return 0;
}
**/
