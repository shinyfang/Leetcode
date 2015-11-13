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
    	vector<int> nums;//�����ۼӵ���
    	int index = 0;//����һ���ۼӵ������±꣬��Ϊ�´��ۼ���Ҫ���ϴ��ۼӵ��±꿪ʼ�������
    	int sum = 0;//�ۼӵ�ֵ��ʼ��Ϊ0
    	csum(candidates,target,nums,result,sum,index);
    	sort(result.begin(),result.end());//��Iһ����ֻ�����������ʱ�������ȥ��
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
    		csum(candidates,target,nums,result,sum,i+1);//��һ�ξ�Ҫ���±�Ϊi+1������ʼ�ۼ�
    		nums.pop_back();//һ�������������֮��Ҫ���������������ܽ�����һ���������
    		sum -= candidates[i];//һ�������������֮��ҲҪ��sum�ָ���ԭֵ������
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
    	vector<int> nums;//�����ۼӵ���
    	int index = 0;//����һ���ۼӵ������±꣬��Ϊ�´��ۼ���Ҫ���ϴ��ۼӵ��±꿪ʼ�������
    	int sum = 0;//�ۼӵ�ֵ��ʼ��Ϊ0
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
    		csum(candidates,target,nums,result,sum,i+1);//��һ�ξ�Ҫ���±�Ϊi+1������ʼ�ۼ�
    		nums.pop_back();//һ�������������֮��Ҫ���������������ܽ�����һ���������
    		//������һ������֮ǰҪ�ж��´��ۼӵ�������һ�β����
    		sum -= candidates[i];
    		//��ΪҪ������һ�����������ԱȽ���ε�ֵ����һ��Ӧ��������ֵ�Ƿ�һ��
    		while (candidates[i] == candidates[i+1] && i < candidates.size())
    		    i++;
    	}
    }
};
