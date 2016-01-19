#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	//����һ�·��ֲ���n�Ƕ��٣����ֻ�������������ôֱ�����������������������������
    	vector<int> r;
    	if (nums.size() == 0)
    		return r;
    	if (nums.size() == 1)
    		return nums;
    	int r1 = nums[0];
    	int c1 = 1;
    	int r2 = r1;
    	int c2 = 1;
    	int i = 1;
    	while (nums[i] == r1)
    	{
    		c1 ++;
    		i ++;
    	}
    	if (i < nums.size())
    	{
    		r2 = nums[i];
    		c2 = 1;
    		i ++;
    	}
    	for (; i < nums.size(); i ++)
    	{
    		if (c1 == 0)
    		{
    			r1 = nums[i];
    			c1 = 1;
    		}
    		else if (c2 == 0)
    		{
    			r2 = nums[i];
    			c2 = 1;
    		}
    		else if (nums[i] == r1)
    			c1 ++;
    		else if (nums[i] == r2)
    			c2 ++;
    		else
    		{
    			c1 --;
    			c2 --;
    		}
    	}
    	//���ϵõ���r1��r2ֻ��nums���������������������������c1��c2ȴ�ǲ�׼ȷ�ģ�������Ҫ���±���һ��õ�c1��c2
    	c1 = 0;
    	c2 = 0;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if (nums[i] == r1)
    			c1 ++;
    		else if (nums[i] == r2)
    			c2 ++;
    	}
    	if (c1 > (nums.size()/3))
    		r.push_back(r1);
    	if (r1 == r2)
    		return r;
    	if (c2 > (nums.size()/3))
    		r.push_back(r2);
    	return r;
    }
};
