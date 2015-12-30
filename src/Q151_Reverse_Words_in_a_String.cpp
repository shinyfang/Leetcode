#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
    	if (s == "")
    		return;
    	stack<char> stk1;//用来临时存储一个字符串
    	stack<char> stk2;//用来存储逆序后的整个字符串
    	for (int i = 0; i < s.length(); i++)
    	{
    		if (s[i] == ' ')
    		{
    			while (s[i] == ' ' && i < s.length())//把多个连续的空过滤
    				i ++;
    			i --;
    			if (!stk1.empty())//如果是多个空没有字母，不管
    			{
    				while (!stk1.empty())//如果空前面有字符，就组成一个字符串
    				{
    					stk2.push(stk1.top());
    					stk1.pop();
    				}
    				stk2.push(' ');
    			}
    		}
    		else
    			stk1.push(s[i]);
    	}
    	if (!stk1.empty())
    	{
    		while (!stk1.empty())
    		{
    			stk2.push(stk1.top());
    			stk1.pop();
    		}
    	}
    	int p = 0;
    	if (!stk2.empty() && stk2.top() == ' ')//如果最后一个字符带空，记得去掉
    		stk2.pop();
    	while (!stk2.empty())
    	{
    		s[p] = stk2.top();
    		stk2.pop();
    		p ++;
    	}
    	s = s.substr(0,p);
    }
};
