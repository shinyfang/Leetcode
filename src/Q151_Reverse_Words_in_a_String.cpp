#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
    	if (s == "")
    		return;
    	stack<char> stk1;//������ʱ�洢һ���ַ���
    	stack<char> stk2;//�����洢�����������ַ���
    	for (int i = 0; i < s.length(); i++)
    	{
    		if (s[i] == ' ')
    		{
    			while (s[i] == ' ' && i < s.length())//�Ѷ�������Ŀչ���
    				i ++;
    			i --;
    			if (!stk1.empty())//����Ƕ����û����ĸ������
    			{
    				while (!stk1.empty())//�����ǰ�����ַ��������һ���ַ���
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
    	if (!stk2.empty() && stk2.top() == ' ')//������һ���ַ����գ��ǵ�ȥ��
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
