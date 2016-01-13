#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
    	//如果用第一个就不能用最后一个；如果不用第一个就能用最后一个
    	if (nums.size() == 0)
    		return 0;
    	if (nums.size() == 1)
    		return nums[0];
    	int r;
    	vector<int> f(nums.size()-1,0);
    	f[0] = nums[0];
    	f[1] = nums[1]>nums[0]?nums[1]:nums[0];
    	for (int i = 2; i < nums.size() - 1; i++)//1~len-1
    		f[i] = f[i-2]+nums[i]>f[i-1]?f[i-2]+nums[i]:f[i-1];
    	r = f[f.size()-1];
    	f[0] = nums[1];
    	f[1] = nums[2]>nums[1]?nums[2]:nums[1];
    	for (int i = 3; i < nums.size(); i ++)//2~len
    		f[i-1] = f[i-3]+nums[i]>f[i-2]?f[i-3]+nums[i]:f[i-2];
    	r = f[f.size()-1]>r?f[f.size()-1]:r;
    	return r;
    }
};
