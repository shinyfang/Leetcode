#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
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
    		cout<<"candidates:"<<candidates[i]<<" new_sum:"<<sum<<endl;
    		nums.push_back(candidates[i]);
    		csum(candidates,target,nums,result,sum,i);//��һ�ξ�Ҫ���±�Ϊi������ʼ�ۼ�
    		nums.pop_back();//һ�������������֮��Ҫ���������������ܽ�����һ���������
    		sum -= candidates[i];//һ�������������֮��ҲҪ��sum�ָ���ԭֵ������
    	}
    }
};
/**int main(){
	vector<int> can;
	can.push_back(2);
	can.push_back(3);
	can.push_back(6);
	can.push_back(7);
	int target = 7;
	Solution s;
	vector<vector<int> > result = s.combinationSum(can,target);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
**/
