#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/**
 * 超时！！！！！！！！！！！！！
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	vector<vector<int> > result;
    	result.push_back(nums);
    	if (nums.size() == 0 || nums.size() == 1)
    		return result;
    	return permu(nums,0,nums.size()-1,result);
    }
    vector<vector<int> > permu(vector<int>& nums, int p1, int p2, vector<vector<int> >& result)
    {
    	if (p1 < p2)
    	{
    		for (int i = p1; i < p2; i++)
    		{
    			for (int j = i+1; j <= p2; j++)
    			{
    				if (nums[i] == nums[j])
    					continue;
    				vector<int> temp = nums;
    				swap(temp[i],temp[j]);
    				result.push_back(temp);
    				permu(temp,i+1,p2,result);
    				//交换后从i+1开始继续交换
    			}
    		}
    	}
    	return result;
    }
};
**/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	vector<vector<int> > result;
    	if (nums.size() == 0 || nums.size() == 1)
    		return result;
    	vector<int> ans; //存当前已经加入某排列的数
    	sort(nums.begin(),nums.end());
    	vector<int> used(nums.size(),0); //记录i位置的数是否已经被用
    	permute(result,nums,ans,used);
    	return result;
    }
    void permute(vector<vector<int> >& result, vector<int> nums, vector<int> ans, vector<int> used)
	{
    	//相当于每次都去寻找要加入候选序列的数字，而不是循环交换
    	if (ans.size() == nums.size()) //全部排序完
    	{
    		result.push_back(ans);
    		return;
    	}
    	for (int i = 0; i < nums.size(); i++) //遍历nums，寻找没有被加入的数
    	{
    		if (used[i] || (i>0 && nums[i] == nums[i-1] && !used[i-1]))
    			continue;
    			//如果这个数已经被用过，或者它与前一个数相等，且前一个数还未被用时，这个数也不能用
    			//也就是，所有重复的数字，必须按顺序用，不存在可以交换相等的数字组成序列
    		ans.push_back(nums[i]);
    		used[i] = 1;
    		permute(result,nums,ans,used);
    		ans.pop_back();
    		used[i] = 0;
    	}
	}
};
/**int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(2);
	vector<vector<int> > result = s.permuteUnique(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}
**/
