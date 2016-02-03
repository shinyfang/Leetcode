#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	map<string,vector<int> > memo;
    vector<int> diffWaysToCompute(string input) {
    	vector<int> result;
    	if (input == "" || input.length() == 0)
    		return result;
    	for (int i = 0; i < input.length(); i ++)
    	{
    		if (input[i] == '+' || input[i] == '-' || input[i] == '*')
    		{
    			vector<int> left;
    			if (memo.find(input.substr(0,i)) != memo.end())
    				left = memo[input.substr(0,i)];
    			else
    				left = diffWaysToCompute(input.substr(0,i));
    			vector<int> right;
    			if (memo.find(input.substr(i+1)) != memo.end())
    				right = memo[input.substr(i+1)];
    			else
    				right = diffWaysToCompute(input.substr(i+1));
    			for (int j = 0; j < left.size(); j ++)
    			{
    				for (int k = 0; k < right.size(); k ++)
    				{
    					if (input[i] == '+')
    						result.push_back(left[j]+right[k]);
    					else if (input[i] == '-')
    						result.push_back(left[j]-right[k]);
    					else
    						result.push_back(left[j]*right[k]);
    				}
    			}
    		}
    	}
    	if (result.empty())//说明没有符号，直接将string转化成数字
    	{
    		int temp = 0;
    		for (int i = 0; i < input.length(); i ++)
    			temp = 10*temp + (input[i] - '0');
    		result.push_back(temp);
    	}
    	memo[input] = result;
    	return result;
    }
};
