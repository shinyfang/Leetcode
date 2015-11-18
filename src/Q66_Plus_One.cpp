#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int n = digits.size();
    	if (digits[n-1] == 9)
    	{
    		bool flag = true;
    		for (int i = n-1; i >= 0; i--)
    		{
    			if (flag)
    			{
    				digits[i] += 1;
    				if (digits[i] >= 10)
    				{
    					digits[i] %= 10;
    				}
    				else
    					flag = false;
    			}
    			else
    				return digits;
    		}
    		if (flag)
    		{
    			digits.insert(digits.begin(),1);
    		}
    		return digits;
    	}
    	else
    	{
    		digits[n-1] += 1;
    		return digits;
    	}
    }
};
