#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int max = 0;
    	if (prices.size() <= 1)
    		return max;
    	for (int i = 1; i < prices.size(); i++)//ֻҪ��׬���Ͱ���׬��Ǯ�ӽ�ȥ
    	{
    		if (prices[i] > prices[i-1])
    			max += (prices[i]-prices[i-1]);
    	}
    	return max;
    }
};
