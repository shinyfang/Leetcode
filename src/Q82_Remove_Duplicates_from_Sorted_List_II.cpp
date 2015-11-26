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
    	//���head->next == NULL,��ôhead->next->val��������������Էֿ����ۣ�����
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
    	p->next = NULL; //����Ϊ�˲���pָ���head����ԭ����head�ߣ�������p->next��ΪNULL������result����
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
