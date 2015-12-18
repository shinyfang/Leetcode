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
    bool hasCycle(ListNode *head) {
    	//双指针，p1每次动一步，p2每次动两步，如果p2绕p1一圈就是形成了环
    	if (head == NULL || head->next == NULL)
    		return false;
    	ListNode* p1 = head;
    	ListNode* p2 = head;
    	while (p1 != NULL && p2 != NULL && p2->next != NULL)//这里保证不会指向未申请空间
    	{
    		p1 = p1->next;
    		p2 = p2->next->next;
    		if (p1 == p2)
    			return true;
    	}
    	return false;
    }
};
