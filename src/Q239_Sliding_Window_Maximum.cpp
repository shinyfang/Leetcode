#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	if (nums.size() == 0)
    		return nums;
    	vector<int> result;
    	set<int> s;
    	for (int i = 0; i < k; i ++)
    		s.insert(nums[i]);
    	result.push_back(*s.rbegin());
    	int i = 0;
    	int j = k;
    	for (; j < nums.size(); j ++)
    	{
    		s.insert(nums[j]);
    		s.erase(s.find(nums[i]));
    		i ++;
    		result.push_back(*s.rbegin());
    	}
    	return result;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	Solution s;
	vector<int> r = s.maxSlidingWindow(nums,3);
	for (int i = 0; i < r.size(); i ++)
		cout<<r[i]<<" ";
	return 0;
}
**/
