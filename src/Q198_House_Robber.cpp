#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
    	//动态规划f表示是否抢这个
    	if (nums.size() == 0)
    		return 0;
    	if (nums.size() == 1)
    		return nums[0];
    	vector<int> f(nums.size(),0);
    	f[0] = nums[0];
    	f[1] = nums[1]>nums[0]?nums[1]:nums[0];
    	for (int i = 2; i < nums.size(); i++)
    		f[i] = f[i-2]+nums[i]>f[i-1]?f[i-2]+nums[i]:f[i-1];
    	return f[nums.size()-1];
    }
};
