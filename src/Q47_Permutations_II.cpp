#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/**
 * ��ʱ��������������������������
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
    				//�������i+1��ʼ��������
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
    	vector<int> ans; //�浱ǰ�Ѿ�����ĳ���е���
    	sort(nums.begin(),nums.end());
    	vector<int> used(nums.size(),0); //��¼iλ�õ����Ƿ��Ѿ�����
    	permute(result,nums,ans,used);
    	return result;
    }
    void permute(vector<vector<int> >& result, vector<int> nums, vector<int> ans, vector<int> used)
	{
    	//�൱��ÿ�ζ�ȥѰ��Ҫ�����ѡ���е����֣�������ѭ������
    	if (ans.size() == nums.size()) //ȫ��������
    	{
    		result.push_back(ans);
    		return;
    	}
    	for (int i = 0; i < nums.size(); i++) //����nums��Ѱ��û�б��������
    	{
    		if (used[i] || (i>0 && nums[i] == nums[i-1] && !used[i-1]))
    			continue;
    			//���������Ѿ����ù�����������ǰһ������ȣ���ǰһ������δ����ʱ�������Ҳ������
    			//Ҳ���ǣ������ظ������֣����밴˳���ã������ڿ��Խ�����ȵ������������
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
