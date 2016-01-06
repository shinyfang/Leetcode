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
    	if (nums[begin] <= nums[mid] && nums[mid] < nums[end])
    		return findM(nums,begin,mid);
    	else if (nums[begin] <= nums[mid] && nums[mid] > nums[end])
    		return findM(nums,mid+1,end);
    	else if (nums[begin] > nums[mid] && nums[mid] < nums[end])
    		return findM(nums,begin,mid);
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	Solution s;
	cout<<s.findMin(nums);
	return 0;
}
**/
