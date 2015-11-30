#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    	vector<vector<int> > result;
    	vector<int> temp;
    	result.push_back(temp);
    	if (nums.size() == 0)
    		return result;
        sort(nums.begin(),nums.end());
        for (int i = 1; i <= nums.size(); i++)
        {
        	vector<vector<int> > temp;
        	vector<int> temp2;
        	combine2(temp,temp2,nums,i,0);
        	for (int j = 0; j < temp.size(); j++)
        		result.push_back(temp[j]);
        }
        return result;
    }
    void combine2(vector<vector<int> >& result, vector<int>& res, vector<int> nums, int k, int start)
    {
    	if (res.size() == k)
    	{
    		result.push_back(res);
    		return;
    	}
    	for (int i = start; i < nums.size(); i++)
    	{
    		if (i == start || nums[i] != nums[i-1])
    		{
    			res.push_back(nums[i]);
				combine2(result,res,nums,k,i+1);
				res.pop_back();
    		}
    	}
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	Solution s;
	vector<vector<int> > result = s.subsetsWithDup(nums);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (int j = 0; j < result[i].size(); j++)
	//		cout<<result[i][j]<<" ";
	//	cout<<endl;
	//}
	return 0;
}
**/
