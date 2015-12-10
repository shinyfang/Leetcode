#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int max = 0;
    	if (prices.size() <= 1)
    		return max;
    	vector<int> maxL(prices.size(),0);
    	vector<int> maxR(prices.size(),0);
    	int minL = prices[0];
    	for (int i = 1; i < prices.size(); i++)
    	{
    		minL = prices[i]<minL?prices[i]:minL;
    		maxL[i] = (prices[i]-minL)>maxL[i-1]?(prices[i]-minL):maxL[i-1];
    	}
    	int maxr = prices[prices.size()-1];
    	for (int i = prices.size() - 2; i >= 0; i--)
    	{
    		maxr = prices[i]>maxr?prices[i]:maxr;
    		maxR[i] = (maxr-prices[i])>maxR[i+1]?(maxr-prices[i]):maxR[i+1];
    	}
    	for (int i = 0; i < prices.size(); i++)
    		max = (maxL[i]+maxR[i])>max?(maxL[i]+maxR[i]):max;
    	return max;
    }
};
