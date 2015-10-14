#include<iostream>
#include<vector>
using namespace std;
//题目意思是返回与val不同的数的长度，而且会检查nums里面前len个数是不是与val不同
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0, j = nums.size()-1; i <= j;)
        {
        	if (nums[i] != val)
        	{
        		len++;
        		i++;
        	}
        	else
        	{
        		nums[i] = nums[j];
        		j--;
        	}
        }
        return len;
    }
};
