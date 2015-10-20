#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int len = nums.size();
    	if (len == 0)
    		return -1;
    	if (len == 1 && target == nums[0])
    		return 0;
    	if (len == 1 && target != nums[0])
    		return -1;
    	if (nums[0] < nums[len-1])//如果本来就是有序的，直接用二分查找
    		return search2(nums,0,len-1,target);
    	else//如果是乱序的，进入search1
    		return search1(nums,0,len-1,target);
    }
    int search1(vector<int>& nums, int p1, int p2, int target)//目的是将乱序的二分，之后判断继续对乱序二分还是直接二分查找
    {
    	while (p1 <= p2)
    	{
			int m = (p1+p2)/2;
			if (nums[m] == target)
				return m;
			if (nums[p1] <= nums[m] && nums[p1] <= target && target <= nums[m])
				return search2(nums,p1,m-1,target);
			else if (nums[m] <= nums[p2] && nums[m] <= target && target <= nums[p2])
				return search2(nums,m+1,p2,target);
			else if (nums[p1] <= nums[m] && (target <= nums[p1] || target >= nums[m]))
				return search1(nums,m+1,p2,target);
			else if (nums[m] <= nums[p2] && (target <= nums[m] || target >= nums[p2]))
				return search1(nums,p1,m-1,target);
			else
				return -1;
    	}
    	return -1;
    }
    int search2(vector<int>& nums, int p1, int p2, int target)
    {
    	while (p1 <= p2)
    	{
			int m = (p1+p2)/2;
			if (nums[m] == target)
				return m;
			else if (target < nums[m])
				return search2(nums,p1,m-1,target);
			else
				return search2(nums,m+1,p2,target);
    	}
    	return -1;

    }
};
/**int main(){
	vector<int> nums;
	//nums.push_back(4);
	//nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	//nums.push_back(0);
	nums.push_back(3);
	nums.push_back(1);
	int target = 1;
	Solution s;
	cout<<s.search(nums,target);
	return 0;
}
**/
