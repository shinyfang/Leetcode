#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	if (nums.size() == 0 || k == 0)
    		return false;
    	int i = 0;
    	int j = 1;
    	set<int> m;//用set来存储k范围内互不相同的数
    	//用双指针来圈定k的范围
    	m.insert(nums[i]);
    	while (j < nums.size())
    	{
    		if (j - i > k)
    		{
    			m.erase(nums[i]);
    			i ++;
    		}
    		while (j - i <= k && j < nums.size())
    		{
    			if (m.find(nums[j]) != m.end())
    				return true;
    			m.insert(nums[j]);
    			j ++;
    		}
    	}
    	return false;
    }
};
