#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	if (nums.size() < 2)
    		return false;
    	map<int,int> m;
    	for (int i = 0; i < nums.size(); i ++)
    		m[nums[i]] ++;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if (m[nums[i]] > 1)
    			return true;
    	}
    	return false;
    }
};
