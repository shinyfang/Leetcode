#include<iostream>
#include<vector>
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)//���Ϊ�ջ���ֻ��һ���ڵ�
        	return head;
        ListNode* result = new ListNode(-1);
        result->next = head;
        ListNode* p = result;
        ListNode* p1 = head;
        while(p1 != NULL && p1->next != NULL)
        {
        	p->next = p1->next;
        	p = p->next;
        	p1->next = p1->next->next;//�Ȱ�p1->next����
        	p->next = p1;
        	p = p->next;
        	p1 = p1->next;
        }
        return result->next;
    }
};
/**int main(){
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	ListNode* result = s.swapPairs(head);
	cout<<result->val<<" "<<result->next->val<<" "<<result->next->next->val<<" "<<result->next->next->next->val<<endl;
	return 0;
}
**/
