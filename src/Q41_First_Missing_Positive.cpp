#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //O(N)说明只能有一个循环
    	//找第一个正数，从1开始算正数，所以nums里面大于nums.size()的值不用考虑位置了
    	//将值i恢复到index=i-1的位置上，因为当这些数都满足它们按顺序排序应该是连续
    	if (nums.size() == 0)
    		return 1;
    	int len = nums.size();//数组能承受的最大数值nums[len-1]=len
    	for (int i = 0; i < len; i++)
    	{
    		//要换的数必须大于0小于等于len
    		while (nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i])
    			swap(nums[i],nums[nums[i]-1]);
    	}
    	for (int i = 0; i < len; i++)
    	{
    		if (nums[i] != i+1)
    			return i+1;
    	}
    	return len+1;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(1);
	Solution s;
	cout<<s.firstMissingPositive(nums);
	return 0;
}
**/
