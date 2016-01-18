#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
    	stack<int> stk;
    	int sign = 1;//默认是正数
    	int res = 0;
    	for (int i = 0; i < s.length(); i ++)
    	{
    		if (s[i] == ' ')
    			continue;
    		if (s[i] == '(')
    		{
    			stk.push(res);//每次遇到优先级括号时，把上次得到的结果存起来
    			stk.push(sign);
    			res = 0;
    			sign = 1;
    		}
    		else if (s[i] == '+')
    			sign = 1;
    		else if (s[i] == '-')
    			sign = -1;
    		else if (s[i] == ')')//遇到优先级结束时，把之前存起来的结果拿出来计算
    		{
    			sign = stk.top();
    			stk.pop();
    			res = sign*res + stk.top();
    			stk.pop();
    			sign = 1;
    		}
    		else
    		{
    			int temp = 0;
    			while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    			{
    				temp = 10*temp + (s[i]-'0');
    				i ++;
    			}
    			i --;
    			res += sign*temp;
    		}
    	}
    	return res;
    }
};
