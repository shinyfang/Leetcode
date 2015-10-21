#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if (nums.size() == 0)
    		return 0;
    	int result = search(nums,0,nums.size()-1,target);
    	//将二分查找改进成找范围
    	return result;
    }
    int search(vector<int>& nums, int p1, int p2, int target)
    {
    	if (target < nums[p1])
    		return p1;
    	if (target > nums[p2])
    		return p2+1;
    	int mid = (p1+p2)/2;
    	if (nums[mid] == target)
    		return mid;
    	else if (nums[mid] < target)
    	{
    		if (target < nums[mid-1])//找范围
    			return mid+1;
    		else
    			search(nums,mid+1,p2,target);//找范围
    	}
    	else
    	{
    		if (target > nums[mid+1])
    			return mid;
    		else
    			search(nums,p1,mid-1,target);
    	}
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	int target = 6;
	Solution s;
	cout<<s.searchInsert(nums,target);
	return 0;
}
**/
