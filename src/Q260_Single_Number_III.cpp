#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	vector<int> result;
    	int x = 0;
    	for (int i = 0; i < nums.size(); i ++)
    		x ^= nums[i];
    	//x-1ȡ��������x�����Եõ�x�����Ʊ�ʾ�ɵ͵���λ��һ��1λ
    	int mask = (x & (~(x-1)));
    	int a = 0;
    	int b = 0;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if ((mask & nums[i]) == 0)//Ҫ�����ţ���Ϊ&�����ȼ�С��==
    			a ^= nums[i];
    		else
    			b ^= nums[i];
    	}
    	result.push_back(a);
    	result.push_back(b);
    	return result;
    }
};
