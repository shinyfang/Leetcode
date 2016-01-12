#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {//注意：大于等于s即可
    	if (nums.size() == 0)
    		return 0;
    	int p1 = 0;
    	int p2 = 1;
    	int count = nums[p1];
    	int r = INT_MAX;
    	while (p1 <= p2 && p2 < nums.size())
    	{
    		while (count < s && p2 < nums.size())
    			count += nums[p2++];
    		while (count >= s && p1 < nums.size() && p1 <= p2)//只要>=s都是可能的答案
    		{
    			r = (p2-p1)<r?(p2-p1):r;//因为此时p2已经指向下一个了，所以不用+1
    			count -= nums[p1++];
    		}
    	}
    	return r==INT_MAX?0:r;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(4);
	//nums.push_back(4);
	//nums.push_back(5);
	Solution s;
	cout<<s.minSubArrayLen(4,nums);
	return 0;
}
**/
