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
    	//˫ָ�룬p1ÿ�ζ�һ����p2ÿ�ζ����������p2��p1һȦ�����γ��˻�
    	if (head == NULL || head->next == NULL)
    		return false;
    	ListNode* p1 = head;
    	ListNode* p2 = head;
    	while (p1 != NULL && p2 != NULL && p2->next != NULL)//���ﱣ֤����ָ��δ����ռ�
    	{
    		p1 = p1->next;
    		p2 = p2->next->next;
    		if (p1 == p2)
    			return true;
    	}
    	return false;
    }
};
