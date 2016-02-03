#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	//�൱��iǰ��˻������˻��ĳ˻�
    	if (nums.size() < 2)
    		return nums;
    	vector<int> right(nums.size(),1);
    	int sum = 1;//��ʼ����1
    	for (int i = nums.size() - 2; i >= 0; i --)
    	{
    		sum *= nums[i+1];
    		right[i] = sum;
    	}
    	sum = nums[0];//��ʼ���ǵ�һ����
    	nums[0] = right[0];
    	for (int i = 1; i < nums.size(); i ++)
    	{
    		int temp = nums[i];
    		nums[i] = sum*right[i];
    		sum *= temp;
    	}
    	return nums;
    }
};
