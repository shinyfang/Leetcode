#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL)
    		return l2;
    	if (l2 == NULL)
    		return l1;
    	ListNode* p1 = l1;
    	ListNode* p2 = l2;//ָ��ָ�����������ͷ����ʾ�������ڱȽϵ������ڵ�
    	if (p1->val <= p2->val){
    		ListNode* p = l1;//����ָ��l1��ǰ�ȽϵĽڵ��ǰһ���ڵ�
    		p1 = p1->next;
    		while(p1 != NULL || p2 != NULL){
    			if (p1 == NULL){//p1Ϊnull��p2�϶���ֵ
    				p->next = p2;
    				return l1;
    			}
    			else if (p2 == NULL){
    				return l1;
    			}
    			else if (p1->val <= p2->val){
    				p1 = p1->next;
    				p = p->next;
    			}
    			else{
    				p->next = p2;//˳�����ƶ�p�����ƶ�p2
    				p2 = p2->next;
    				p = p->next;
    				p->next = p1;
    			}
    		}
    	}
    	else{
    		ListNode* p = l2;
    		p2 = p2->next;
    		while(p1 != NULL || p2 != NULL){
    			if (p2 == NULL){
    				p->next = p1;
    				return l2;
    			}
    			else if (p1 == NULL){
    				return l2;
    			}
    			else if (p2->val <= p1->val){
    				p2 = p2->next;
    				p = p->next;
    			}
    			else{
    				p->next = p1;
    				p1 = p1->next;
    				p = p->next;
    				p->next = p2;
    			}
    		}
    	}
    }
};
/**int main(){
	Solution s;
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(5);
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(6);
	ListNode* result = s.mergeTwoLists(l1,l2);
	cout<<result->val<<" "<<result->next->val<<" "<<result->next->next->val<<" "<<result->next->next->next->val<<" "<<result->next->next->next->next->val<<" "<<result->next->next->next->next->next->val<<endl;
	return 0;
}
**/
