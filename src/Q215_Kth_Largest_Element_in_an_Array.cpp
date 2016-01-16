#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	priority_queue<int,deque<int>,greater<int> > q;
    	int i = 0;
    	while (k --)
    		q.push(nums[i++]);
    	for (; i < nums.size(); i ++)
    	{
    		if (nums[i]>q.top())
    		{
    			q.pop();
    			q.push(nums[i]);
    		}
    	}
    	return q.top();
    }
};
