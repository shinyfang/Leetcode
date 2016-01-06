#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int result = nums[0];
    	int num = 1;
    	for (int i = 1; i < nums.size(); i++)
    	{
    		if (num == 0)
    			result = nums[i];
    		if (nums[i] == result)
    			num ++;
    		else
    			num --;
    	}
    	return result;
    }
};
