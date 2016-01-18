#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
    	stack<int> stk;
    	int sign = 1;//Ĭ��������
    	int res = 0;
    	for (int i = 0; i < s.length(); i ++)
    	{
    		if (s[i] == ' ')
    			continue;
    		if (s[i] == '(')
    		{
    			stk.push(res);//ÿ���������ȼ�����ʱ�����ϴεõ��Ľ��������
    			stk.push(sign);
    			res = 0;
    			sign = 1;
    		}
    		else if (s[i] == '+')
    			sign = 1;
    		else if (s[i] == '-')
    			sign = -1;
    		else if (s[i] == ')')//�������ȼ�����ʱ����֮ǰ�������Ľ���ó�������
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
