#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	//计算一下发现不管n是多少，最多只有两个结果，那么直接申请两个变量存这两个结果即可
    	vector<int> r;
    	if (nums.size() == 0)
    		return r;
    	if (nums.size() == 1)
    		return nums;
    	int r1 = nums[0];
    	int c1 = 1;
    	int r2 = r1;
    	int c2 = 1;
    	int i = 1;
    	while (nums[i] == r1)
    	{
    		c1 ++;
    		i ++;
    	}
    	if (i < nums.size())
    	{
    		r2 = nums[i];
    		c2 = 1;
    		i ++;
    	}
    	for (; i < nums.size(); i ++)
    	{
    		if (c1 == 0)
    		{
    			r1 = nums[i];
    			c1 = 1;
    		}
    		else if (c2 == 0)
    		{
    			r2 = nums[i];
    			c2 = 1;
    		}
    		else if (nums[i] == r1)
    			c1 ++;
    		else if (nums[i] == r2)
    			c2 ++;
    		else
    		{
    			c1 --;
    			c2 --;
    		}
    	}
    	//以上得到的r1和r2只是nums里面出现最多次数的两个数，但是c1和c2却是不准确的，所以需要重新遍历一遍得到c1和c2
    	c1 = 0;
    	c2 = 0;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if (nums[i] == r1)
    			c1 ++;
    		else if (nums[i] == r2)
    			c2 ++;
    	}
    	if (c1 > (nums.size()/3))
    		r.push_back(r1);
    	if (r1 == r2)
    		return r;
    	if (c2 > (nums.size()/3))
    		r.push_back(r2);
    	return r;
    }
};
