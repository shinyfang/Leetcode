#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	//n+1个数范围是1-n，若没有重复<=i的个数为i，若有重复<=i的个数大于i
    	int l = 1;
    	int r = nums.size()-1;
    	while (l < r)
    	{
    		int mid = l + (r - l) / 2;
    		int count = 0;
    		for (int i = 0; i < nums.size(); i ++)
    			count += (nums[i]<=mid?1:0);
    		if (count <= mid)
    			l = mid + 1;
    		else
    			r = mid;
    	}
    	return l;
    }
};
