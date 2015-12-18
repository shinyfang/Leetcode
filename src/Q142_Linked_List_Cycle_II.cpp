#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {//»­Í¼»á·¢ÏÖa == c
    	if (head == NULL || head->next == NULL)
    		return NULL;
    	ListNode* p1 = head;
    	ListNode* p2 = head;
    	while (p1 != NULL && p2 != NULL && p2->next != NULL)
    	{
    		p1 = p1->next;
    		p2 = p2->next->next;
    		if (p1 == p2)
    		{
    			ListNode* p3 = head;
    			while (p3 != p1)
    			{
    				p3 = p3->next;
    				p1 = p1->next;
    			}
    			return p3;
    		}
    	}
    	return NULL;
    }
};
