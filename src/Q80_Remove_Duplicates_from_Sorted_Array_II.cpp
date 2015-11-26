#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() == 0 || nums.size() == 1)
    		return nums.size();
    	int p = 0;
    	bool flag = false;
    	for (int i = 1; i < nums.size(); i++)
    	{
    		if (!flag && nums[i] == nums[i-1])
    		{
    			p++;
    			nums[p] = nums[i];
    			flag = true;
    		}
    		else if (flag && nums[i] == nums[i-1])
    			continue;
    		else
    		{
    			//nums[i] != nums[i-1]
    			p++;
    			nums[p] = nums[i];
    			flag = false;
    		}
    	}
    	return p+1;
    }
};
/**int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	Solution s;
	cout<<s.removeDuplicates(nums);
	return 0;
}
**/
