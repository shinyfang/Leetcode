#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	//Äæ²¨À¼±íÊ¾·¨
    	if (tokens.size() == 0)
    		return 0;
    	stack<int> stk;
    	for (int i = 0; i < tokens.size(); i++)
    	{
    		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
    		{
    			if (stk.empty())
    				continue;
    			int b = stk.top();
    			stk.pop();
    			if (stk.empty())
    				continue;
    			int a = stk.top();
    			stk.pop();
    			int c = 0;
    			if (tokens[i] == "+")
    				c = a + b;
    			else if (tokens[i] == "-")
    				c = a - b;
    			else if (tokens[i] == "*")
    				c = a * b;
    			else
    				c = a / b;
    			stk.push(c);
    		}
    		else
    		{
    			int p = str2num(tokens[i]);
    			stk.push(p);
    		}
    	}
    	return stk.top();
    }
    int str2num(string s)
    {
    	int num;
    	stringstream ss(s);
    	ss>>num;
    	return num;
    }
};
