#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**class Solution {
public:
    vector<vector<int > > combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int> > result;
    	sort(candidates.begin(),candidates.end());
    	if (candidates.size() == 0 || target < candidates[0])
    		return result;
    	vector<int> nums;//存已累加的数
    	int index = 0;//存上一次累加的数的下标，因为下次累加需要从上次累加的下标开始往后遍历
    	int sum = 0;//累加的值初始化为0
    	csum(candidates,target,nums,result,sum,index);
    	sort(result.begin(),result.end());//和I一样，只是最后输出结果时候进行了去重
    	result.erase(unique(result.begin(),result.end()),result.end());
    	return result;
    }
    void csum(vector<int> candidates, int target, vector<int>& nums, vector<vector<int> >& result, int sum, int index)
    {
    	if (target < sum)
    		return;
    	if (target == sum)
    	{
    		result.push_back(nums);
    		return;
    	}
    	for (int i = index; i < candidates.size(); i++)
    	{
    		sum += candidates[i];
    		int temp = sum;
    		cout<<"candidates:"<<candidates[i]<<" new_sum:"<<sum<<endl;
    		nums.push_back(candidates[i]);
    		csum(candidates,target,nums,result,sum,i+1);//下一次就要从下标为i+1的数开始累加
    		nums.pop_back();//一个深度搜索完了之后要弹出来，这样才能进行下一个深度搜索
    		sum -= candidates[i];//一个深度搜索完了之后也要把sum恢复成原值！！！
    	}
    }
};
**/
class Solution {
public:
    vector<vector<int > > combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int> > result;
    	sort(candidates.begin(),candidates.end());
    	if (candidates.size() == 0 || target < candidates[0])
    		return result;
    	vector<int> nums;//存已累加的数
    	int index = 0;//存上一次累加的数的下标，因为下次累加需要从上次累加的下标开始往后遍历
    	int sum = 0;//累加的值初始化为0
    	csum(candidates,target,nums,result,sum,index);
    	return result;
    }
    void csum(vector<int> candidates, int target, vector<int>& nums, vector<vector<int> >& result, int sum, int index)
    {
    	if (target < sum)
    		return;
    	if (target == sum)
    	{
    		result.push_back(nums);
    		return;
    	}
    	for (int i = index; i < candidates.size(); i++)
    	{
    		sum += candidates[i];
    		int temp = sum;
    		//cout<<"candidates:"<<candidates[i]<<" new_sum:"<<sum<<endl;
    		nums.push_back(candidates[i]);
    		csum(candidates,target,nums,result,sum,i+1);//下一次就要从下标为i+1的数开始累加
    		nums.pop_back();//一个深度搜索完了之后要弹出来，这样才能进行下一个深度搜索
    		//进行下一个搜索之前要判断下次累加的数与上一次不相等
    		sum -= candidates[i];
    		//因为要进行下一个搜索，所以比较这次的值与下一次应该搜索的值是否一样
    		while (candidates[i] == candidates[i+1] && i < candidates.size())
    		    i++;
    	}
    }
};
