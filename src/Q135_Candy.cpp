#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
    	if (ratings.size() == 0)
    		return 0;
    	int total = 1;
    	int start = 0;
    	int pre = 1;
    	for (int i = 1; i < ratings.size(); i++)
    	{
    		if (ratings[i] > ratings[i-1])//如果递增就直接加1
    		{
    			start = i;
    			pre += 1;
    			total += pre;
    		}
    		else if (ratings[i] == ratings[i-1])//相等可以恢复1
    		{
    			start = i;
    			pre = 1;
    			total += pre;
    		}
    		else//递减就要考虑，连着多少个递减
    		{
    			int temp = 0;
    			while (i < ratings.size() && ratings[i] < ratings[i-1])//找递减数列的尾巴
    			{
    				temp ++;
    				i ++;
    			}
    			i --;//注意这里要恢复i
    			if (pre <= temp)
    				total += (temp - pre + 1);//前面递增的尾巴要更改
    			total += (1+temp)*temp/2;//递减的最后一个人给1，往前依次递增，递增和公式
    			pre = 1;
    		}
    	}
    	return total;
    }
};
