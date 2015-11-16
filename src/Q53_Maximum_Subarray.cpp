#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	//最大连续子序列和
    	int max = nums[0];
    	int sum = nums[0];//记录到第i个数的前一个数为止，最大和
    	for (int i = 1; i < nums.size(); i++)
    	{
    		max = sum>max?sum:max;
    		if (sum <= 0)
    			sum = nums[i];//如果之前的和是负数，那计算到i为止的最大子序列就只能是第i个数本身
    		else
    			sum += nums[i];//否则可以加上这个数
    	}
    	max = sum>max?sum:max;
    	return max;
    }
};
/**int main(){
	Solution s;
	vector<int> num;
	num.push_back(-2);
	num.push_back(1);
	num.push_back(-3);
	num.push_back(4);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-5);
	num.push_back(4);
	cout<<s.maxSubArray(num);
	return 0;
}
**/
