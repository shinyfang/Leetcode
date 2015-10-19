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
/**
 * 超时
 * class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return NULL;
		ListNode* result = lists[0];
		for (int i = 1; i < lists.size(); i++){
			result = merge2Lists(result, lists[i]);
		}
		return result;
	}
	ListNode* merge2Lists(ListNode* l1, ListNode* l2){
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* result = new ListNode(-1);
		ListNode* p = result;
		while(l1 != NULL || l2 != NULL){
			if (l1 == NULL)
			{
				p->next = l2;
				return result->next;
			}
			if (l2 == NULL)
			{
				p->next = l1;
				return result->next;
			}
			if(l1->val <= l2->val)
			{
				p->next = l1;
				p = p->next;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
		}
		return result->next;
	}
};
**/

//不断的两两合并或者归并
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode*> temp;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i])
				temp.push_back(lists[i]);
		}//去除vector中的空链表
		if (temp.size() == 0)
			return NULL;
		vector<ListNode*> result = temp;
		while(temp.size() > 1)//直到合并为一个链表
		{
			result.clear();
			for (int i = temp.size()-2; i >= 0;)//两两合并
			{
				ListNode* p = merge2Lists(temp[i], temp[i+1]);
				result.push_back(p);
				i -= 2;
			}
			if (temp.size()%2 == 1)
				result.push_back(temp[0]);
			temp = result;
		}
		return result[0];
	}
	ListNode* merge2Lists(ListNode* l1, ListNode* l2){
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* result = new ListNode(-1);
		ListNode* p = result;
		while(l1 != NULL || l2 != NULL){
			if (l1 == NULL)
			{
				p->next = l2;
				return result->next;
			}
			if (l2 == NULL)
			{
				p->next = l1;
				return result->next;
			}
			if(l1->val <= l2->val)
			{
				p->next = l1;
				p = p->next;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
		}
		return result->next;
	}
};

/**int main() {
	 Solution s;
	 vector<ListNode*> Lists;
	 ListNode* l1 = new ListNode(1);
	 l1->next = new ListNode(3);
	 l1->next->next = new ListNode(5);
	 ListNode* l2 = new ListNode(2);
	 l2->next = new ListNode(4);
	 l2->next->next = new ListNode(8);
	 ListNode* l3 = new ListNode(6);
	 l3->next = new ListNode(7);
	 l3->next->next = new ListNode(9);
	//ListNode* l1 = NULL;
	//ListNode* l2 = NULL;
	//ListNode* l3;
	Lists.push_back(l1);
	Lists.push_back(l2);
	Lists.push_back(l3);
	ListNode* result = s.mergeKLists(Lists);
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	return 0;
}
**/
