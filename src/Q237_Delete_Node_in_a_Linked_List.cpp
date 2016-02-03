#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {//题目说了node不会是最后一个节点
    	node->val = node->next->val;
    	node->next = node->next->next;
    }
};
