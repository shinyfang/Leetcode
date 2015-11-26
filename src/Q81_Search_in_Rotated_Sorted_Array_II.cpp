#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	sort(nums.begin(),nums.end());
    	if (nums.size() == 0 || target < nums[0] || target > nums[nums.size()-1])
    		return false;
    	bool result = sear(nums,target,0,nums.size()-1);
    	return result;
    }
    bool sear(vector<int> &nums, int target, int l, int r)
    {
    	if (l > r || l < 0 || r > nums.size()-1)
    		return false;
    	int mid = (l + r)/2;
    	if (nums[mid] == target)
    		return true;
    	else if (nums[mid] < target)
    	{
    		while (mid + 1 < nums.size() && nums[mid+1] == nums[mid])
    			mid++;
    		sear(nums,target,mid+1,r);
    	}
    	else
    	{
    		while (mid - 1 >= 0 && nums[mid] == nums[mid-1])
    			mid--;
    		sear(nums,target,l,mid-1);
    	}
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	int target = 1;
	Solution s;
	cout<<s.search(nums,target);
	return 0;
}
**/
