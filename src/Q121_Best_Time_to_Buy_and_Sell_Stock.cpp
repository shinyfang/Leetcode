#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        	return 0;
        int maxprice = prices[prices.size()-1];
        int maxprofit = 0;
        for (int i = prices.size()-1; i >= 0; i--){
        	maxprice = prices[i]>maxprice?prices[i]:maxprice;
        	maxprofit = (maxprice-prices[i])>maxprofit?(maxprice-prices[i]):maxprofit;
        }
        return maxprofit;
    }
};
