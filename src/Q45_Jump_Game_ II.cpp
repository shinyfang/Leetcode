#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 动态规划超时！！！！！！！！！！！！！！！！！！！
 * class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
        	return 0;
        vector<int> temp;
        temp.push_back(0);
        for (int i = 1; i < nums.size(); i++)
        {
        	for (int j = 0; j < i; j++)
        	{
        		if (nums[j] >= (i-j))
        		{
        			temp.push_back(temp[j]+1);
        			break;
        		}
        	}
        }
        return temp[nums.size()-1];
    }
};
**/
class Solution {
public:
    int jump(vector<int>& nums) {
    	int step = 0;
    	int current = 0;
    	int next = 0;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if (i > current)
    		{
    			//<current范围内的格子step步就能走到，<current格子只有再走一步
    			step++;
    			current = next;
    		}
    		next = (i+nums[i]>next)?(i+nums[i]):next;
    		//每次都要更新能走的最远距离

    	}
    	return step;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	Solution s;
	cout<<s.jump(nums);
	return 0;
}
**/
