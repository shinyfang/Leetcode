#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	if (nums.size() == 0)
    		return;
    	int begin = -1;
    	int end = nums.size()-1;
    	int p = 0;
    	while (p <= end)
    	{
    		if (nums[p] == 0)
    		{
    			begin ++;
    			swap(nums[begin],nums[p]);
    			p ++;
    		}
    		else if (nums[p] == 2)
    		{
    			swap(nums[p],nums[end]);
    			end --;
    		}
    		else
    			p ++;
    	}
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	Solution s;
	s.sortColors(nums);
	for (int i = 0; i < nums.size(); i++)
		cout<<nums[i];
	return 0;
}
**/
