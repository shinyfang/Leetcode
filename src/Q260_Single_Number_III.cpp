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
    	//x-1取反，再与x，可以得到x二进制表示由低到高位第一个1位
    	int mask = (x & (~(x-1)));
    	int a = 0;
    	int b = 0;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if ((mask & nums[i]) == 0)//要加括号，因为&的优先级小于==
    			a ^= nums[i];
    		else
    			b ^= nums[i];
    	}
    	result.push_back(a);
    	result.push_back(b);
    	return result;
    }
};
