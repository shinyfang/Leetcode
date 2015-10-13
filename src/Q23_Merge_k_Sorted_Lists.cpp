#include<iostream>
#include<vector>
#define INT_MAX 100
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
/**int main() {
	Solution s;
	vector<ListNode*> Lists;
	ListNode* l1 = new ListNode(1);
	 /**l1->next = new ListNode(3);
	 l1->next->next = new ListNode(5);**/
	 //ListNode* l2 = new ListNode(2);
	 /**l2->next = new ListNode(4);
	 l2->next->next = new ListNode(8);
	 ListNode* l3 = new ListNode(6);
	 l3->next = new ListNode(7);
	 l3->next->next = new ListNode(9);
	//ListNode* l1 = NULL;
	//ListNode* l2 = NULL;
	//ListNode* l3;
	Lists.push_back(l1);
	Lists.push_back(l2);
	//Lists.push_back(l3);
	ListNode* result = s.mergeKLists(Lists);
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	return 0;
}
**/
