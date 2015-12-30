#include<iostream>
#include<vector>
using namespace std;
/**
 *TLE!!!!!!!!!!
 *class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	if (nums.size() == 0)
    		return 0;
    	//因为有负数，所以维护最大堆和最小堆
    	vector<int> max;
    	max.push_back(nums[0]);
    	vector<int> min;
    	min.push_back(nums[0]);
    	for (int i = 1; i < nums.size(); i++)
    	{
    		if (nums[i] * max[i-1] > max[i-1])
    			max[i] = nums[i] * max[i-1];
    		else
    			max[i] = nums[i];
    		if (nums[i] * min[i-1] > max[i])
    			max[i] = nums[i] * min[i-1];
    		if (nums[i] * min[i-1] < min[i-1])
    			min[i] = nums[i] * min[i-1];
    		else
    			min[i] = nums[i];
    		if (nums[i] * max[i-1] < min[i])
    			min[i] = nums[i] * max[i-1];
    	}
    	int result = max[0];
    	for (int i = 0; i < max.size(); i++)
    		result = max[i]>result?max[i]:result;
    	return result;
    }
};
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	if (nums.size() == 0)
    		return 0;
    	if (nums.size() == 1)
    		return nums[0];
    	int max = nums[0];
    	int min = nums[0];//存局部最大最小
    	int result = nums[0];
    	for (int i = 1; i < nums.size(); i++)
    	{
    		int temp = max;
    		if (nums[i]*max >= max && nums[i]*max >= nums[i])//注意这里要加上第二个条件！！！！！否则max=0的时候会出错！！
    			max = nums[i]*max;
    		else
    			max = nums[i];
    		if (nums[i]*min > max)
    			max = nums[i]*min;
    		if (nums[i]*min <= min && nums[i]*min <= nums[i])
    			min = nums[i]*min;
    		else
    			min = nums[i];
    		if (nums[i]*temp < min)
    			min = nums[i]*temp;
    		result = max>result?max:result;
    	}
    	return result;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(-5);
	nums.push_back(4);
	Solution s;
	cout<<s.maxProduct(nums);
	return 0;
}
**/
