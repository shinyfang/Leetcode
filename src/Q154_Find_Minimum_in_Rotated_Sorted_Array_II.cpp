#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
    	if (nums.size() == 0)
    		return 0;
    	return findM(nums,0,nums.size()-1);
    }
    int findM(vector<int>& nums, int begin, int end)
    {
    	if (begin == end)
    		return nums[begin];
    	int mid = (begin + end) / 2;
    	if (nums[begin] == nums[mid] && nums[mid] == nums[end])
    	{
    		//三者都相等，要两边都考虑
    		int left = findM(nums,begin,mid);
    		int right = findM(nums,mid+1,end);
    		return left<right?left:right;
    	}
    	else if (nums[begin] <= nums[mid] && nums[mid] <= nums[end])//这里要有=号
    		return findM(nums,begin,mid);
    	else if (nums[begin] <= nums[mid] && nums[mid] > nums[end])
    		return findM(nums,mid+1,end);
    	else if (nums[begin] > nums[mid] && nums[mid] <= nums[end])//也要加=号
    		return findM(nums,begin,mid);
    }
};
