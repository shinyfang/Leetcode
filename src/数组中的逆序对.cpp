#include<iostream>
#include<vector>
using namespace std;
//�鲢��������ԣ�����
class Solution{
public:
	int InversePairs(vector<int> nums)
	{
		if (nums.size() <= 1)
			return 0;
		vector<int> copy(nums);//copy����֮������
		return InPairs(nums,copy,0,nums.size()-1);
	}
	int InPairs(vector<int>& nums, vector<int>& copy, int begin, int end)
	{
		if (begin == end)
		{
			copy[begin] = nums[begin];//��ʾ������λ��
			return 0;
		}
		int length = (end-begin)/2;
		int left = InPairs(nums,copy,begin,begin+length);
		int right = InPairs(nums,copy,begin+length+1,end);//�ݹ������������С�����ڵ�����ԣ��������������Ѿ�����
		int i = begin + length;//�������β
		int j = end;//�������β�ͣ���ʼ�������������������
		int new_index = end;//�����index���Ӵ�С��������index��ʼ��Ϊend
		int count = 0;//�����������
		while (i >= begin && j >= begin + length + 1)//�пɱȽϵ�ij
		{
			if (nums[i] > nums[j])
			{
				//�ҵ��������
				count += (j-begin-length);//i�᲻�ϱ仯��������ָ��������������Ե�����
				copy[new_index--] = nums[i--];//����copy��д��ϴ����
			}
			else
			{
				copy[new_index--] = nums[j--];
			}
		}
		//��ʱ������С����δд��
		for (;i >= begin; i--)
			copy[new_index--] = nums[i];
		for (; j >= begin + length + 1; j--)
			copy[new_index--] = nums[j];
		nums = copy;//ÿ�ζ�Ҫ����nums
		return (left+right+count);
	}
};
/**int main(){
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);
	Solution s;
	cout<<s.InversePairs(nums);
	return 0;
}
**/
