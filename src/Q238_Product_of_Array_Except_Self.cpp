#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	//相当于i前面乘积与后面乘积的乘积
    	if (nums.size() < 2)
    		return nums;
    	vector<int> right(nums.size(),1);
    	int sum = 1;//初始化是1
    	for (int i = nums.size() - 2; i >= 0; i --)
    	{
    		sum *= nums[i+1];
    		right[i] = sum;
    	}
    	sum = nums[0];//初始化是第一个数
    	nums[0] = right[0];
    	for (int i = 1; i < nums.size(); i ++)
    	{
    		int temp = nums[i];
    		nums[i] = sum*right[i];
    		sum *= temp;
    	}
    	return nums;
    }
};
