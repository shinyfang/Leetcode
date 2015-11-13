#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
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
/**int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int> > result = s.permute(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}
**/
