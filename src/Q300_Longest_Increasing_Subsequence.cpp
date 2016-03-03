#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.size() < 2)
    		return nums.size();
    	vector<int> f;
    	f.push_back(nums[0]);
    	for (int i = 1; i < nums.size(); i ++)
    	{
    		if (nums[i] > f[f.size()-1])
    			f.push_back(nums[i]);
    		else
    		{
    			int begin = 0;
    			int end = f.size()-1;
    			int replace;
    			while (begin <= end)
    			{
    				int mid = begin + (end-begin)/2;
    				if (f[mid] >= nums[i])
    				{
    					replace = mid;
    					end = mid - 1;
    				}
    				else
    				{
    					begin = mid + 1;
    				}
    			}
    			f[replace] = nums[i];
    		}
    	}
    	return f.size();
    }
};
