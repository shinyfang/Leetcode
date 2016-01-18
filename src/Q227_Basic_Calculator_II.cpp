#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
    	if (s == "")
    		return 0;
    	vector<int> vct;
    	for (int i = 0; i < s.length(); i ++)
    	{
    		if (s[i] == ' ')
    			continue;
    		if (s[i] == '+')
    			vct.push_back(1);
    		else if (s[i] == '-')
    			vct.push_back(-1);
    		else if (s[i] == '*' || s[i] == '/')
    		{
    			char op = s[i];
    			i ++;
    			while (i < s.length() && s[i] == ' ')//过滤掉*/之后的空格
    				i ++;
    			int temp = 0;
    			int sign = 1;
    			if (s[i] == '-')
    			{
    				sign = -1;
    				i ++;
    			}
    			while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    			{
    				temp = 10*temp + (s[i] - '0');
    				i ++;
    			}
    			i --;
    			int res = 0;
    			if (op == '*')
    				res = sign*temp*vct[vct.size()-1];
    			else
    				res = sign*vct[vct.size()-1]/temp;
    			vct.pop_back();
    			vct.push_back(res);
    		}
    		else
    		{
    			int temp = 0;
    			while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    			{
    				temp = temp*10 + (s[i] - '0');
    				i ++;
    			}
    			i --;
    			vct.push_back(temp);
    		}
    	}
    	int result = 0;
    	int add = 1;
    	for (int i = 0; i < vct.size(); i ++)
    	{
    		if (i%2 == 0)
    			result += add*vct[i];
    		else
    		{
    			add = vct[i];
    		}
    	}
    	return result;
    }
};
