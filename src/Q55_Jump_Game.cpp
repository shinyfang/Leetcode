#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
    	int step = 0;
    	int current = 0;
    	int next = 0;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if (i > current)
    		{
    			//每次要更新current时，如果更新后current仍不动，说明此时已经走不动了，也永远走不到终点了
    			if (current == next)
    				return false;
    			//<current范围内的格子step步就能走到，<current格子只有再走一步
    			step++;
    			current = next;
    		}
    		//每次都要更新能走的最远距离
    		next = (i+nums[i]>next)?(i+nums[i]):next;
    		if (next+nums[next] >= nums.size())
    			return true;
    	}
    	return true;
	}
};
/**int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	//nums.push_back(1);
	//nums.push_back(0);
	//nums.push_back(4);
	Solution s;
	cout<<s.canJump(nums);
	return 0;
}
**/
