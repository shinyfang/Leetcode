#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	vector<vector<int> > result;
    	vector<int> temp;
        result.push_back(temp); //注意提前把[]加入答案中
        if (nums.size() == 0)
        	return result;
        sort(nums.begin(),nums.end());
        for (int i = 1; i <= nums.size(); i++) //从1找到nums.size()长度
        {
        	vector<vector<int> > temp = combine(nums,nums.size(), i);
        	for (int j = 0; j < temp.size(); j++)
        		result.push_back(temp[j]);
        }
        return result;
    }
    vector<vector<int> > combine(vector<int> nums, int n, int k) {
    		vector<vector<int> > result;
    		if (k > 1)
    		{
    			k--;
    			n--;
    			result = combine(nums, n, k);
    			vector<vector<int> > temp1;
    			for (int i = 0; i < result.size(); i++)
    			{
    				for (vector<int>::iterator j = find(nums.begin(),nums.end(),result[i][result[i].size()-1])+1; j <= nums.begin() + n; j++)
    				{//注意这里，在k--和n--递归完之后，要恢复n，使得k长度能正常写入
    					vector<int> temp2 = result[i];
    					temp2.push_back(*j);
    					temp1.push_back(temp2);
    				}
    			}
    			result.clear();
    			result = temp1;
    		}
    		else
    		{
    			for (int i = 1; i <= n; i++)
    			{
    				vector<int> temp;
    				temp.push_back(nums[i-1]);
    				result.push_back(temp);
    			}
    		}
    		return result;
    	}
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(4);
	//nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	//nums.push_back(8);
	//nums.push_back(10);
	//nums.push_back(0);
	Solution s;
	vector<vector<int> > result = s.subsets(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}
**/
