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
    	//Éî¿½±´£¿£¿£¿
    	if (head == NULL)
    		return head;
    	RandomListNode* p = head;
    	while (p != NULL)
    	{
    		RandomListNode* temp = new RandomListNode(p->label);
    		p->next = temp->next;
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
    	RandomListNode nhead(-1);
    	RandomListNode* np = head;
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
