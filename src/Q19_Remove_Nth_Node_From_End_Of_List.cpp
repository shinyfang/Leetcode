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
    	if (n == 0)//如果不用去除节点，直接返回
    		return head;
    	ListNode* temp = head;
    	int len = 0;
    	while(temp){
    		len++;
    		temp = temp->next;
    	}
    	if (len < 2)//如果链表为空或者只有一个节点，返回空链表
    		return result;
    	if (n == len)//如果是去除头指针，直接返回头指针以后的即可
    		return head->next;
    	cout<<"len:"<<len<<endl;
    	int remove = len-n;//从前往后可以保留几个数
    	cout<<"remove:"<<remove<<endl;
    	int index = 0;//标记现在保留了几个数
    	ListNode* point = head;//指针指向链表头
    	while(1){//不会出现去除头指针的情况
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
