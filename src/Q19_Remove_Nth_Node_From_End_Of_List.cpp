#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* result = NULL;
    	if (n == 0)//�������ȥ���ڵ㣬ֱ�ӷ���
    		return head;
    	ListNode* temp = head;
    	int len = 0;
    	while(temp){
    		len++;
    		temp = temp->next;
    	}
    	if (len < 2)//�������Ϊ�ջ���ֻ��һ���ڵ㣬���ؿ�����
    		return result;
    	if (n == len)//�����ȥ��ͷָ�룬ֱ�ӷ���ͷָ���Ժ�ļ���
    		return head->next;
    	cout<<"len:"<<len<<endl;
    	int remove = len-n;//��ǰ������Ա���������
    	cout<<"remove:"<<remove<<endl;
    	int index = 0;//������ڱ����˼�����
    	ListNode* point = head;//ָ��ָ������ͷ
    	while(1){//�������ȥ��ͷָ������
    		index++;
    		if (index == remove){
    			point->next = point->next->next;
    			break;
    		}
    		point = point->next;
    	}
    	result = head;
    	return result;
    }
};
/**int main(){
	Solution s;
	ListNode* head = new ListNode(1);
	//head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	int n = 1;
	ListNode* result = s.removeNthFromEnd(head,n);
	cout<<result->val<<" "<<result->next->val<<" "<<result->next->next->val<<" "<<result->next->next->next->val<<endl;
	return 0;
}
**/
