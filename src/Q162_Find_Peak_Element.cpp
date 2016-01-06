#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	int l = 0;
    	int r = nums.size() - 1;
    	while (1 <= r)
    	{
    		if (l == r)
    			return l;
    		int mid = (l + r) / 2;
    		if (l == mid && nums[mid] > nums[mid+1])
    			return mid;
    		else if (l == mid && nums[mid] <= nums[mid+1])
    			l = mid + 1;
    		else if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
    			return mid;
    		else if (nums[mid-1] > nums[mid])
    			r = mid - 1;
    		else if (nums[mid] < nums[mid+1])
    			l = mid + 1;
    	}
    }
};
