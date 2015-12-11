#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {//普通的vector查找会超时，想到用hash，map和unordered_map都可以
    	if (nums.size() == 0)
    		return 0;
    	int longest = 0;
    	//unordered_map<int, bool> used;提交的时候用这个
    	map<int, bool> used;
    	for (int i = 0; i < nums.size(); i++)
    		used[nums[i]] = false;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if (!used[nums[i]])
    		{
    			int max = 1;
    			used[nums[i]] = true;
    			for (int j = nums[i] + 1; used.find(j) != used.end(); j++)
    			{
    				max ++;
    				used[j] = true;
    			}
    			for (int j = nums[i] - 1; used.find(j) != used.end(); j--)
    			{
    				max ++;
    				used[j] = true;
    			}
    			longest = max>longest?max:longest;
    		}
    	}
    	return longest;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(100);
	nums.push_back(4);
	nums.push_back(200);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	Solution s;
	cout<<s.longestConsecutive(nums);
	return 0;
}
**/
