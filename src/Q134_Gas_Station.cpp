#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	if (gas.size() == 0)
    		return 0;
    	//最终绕一圈都需要把gas和cost累加起来，只是起点会变
    	int start = 0;
    	int total = 0;
    	int sum = 0;
    	for (int i = 0; i < gas.size(); i++)
    	{
    		sum += (gas[i] - cost[i]);
    		total += sum;
    		if (sum < 0)
    		{
    			start = i + 1;
    			sum = 0;
    		}
    	}
    	return total >= 0 ? start : -1;
    }
};
