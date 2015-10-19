#include<iostream>
#include<string>
#include<stack>
#include<cstring>//memset��ͷ�ļ�
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
    	int len = s.length();
    	if (len < 2)
    		return 0;
    	bool *flag = new bool[len];//���볤Ϊlen�����飬���洢������Ƿ񹹳���ƥ��ķ���
    	memset(flag,false,len);//��ʼ����Ϊfalse
    	stack<int> stk;//stack�������ǿ�����Եķ��ŵ�index��֮������������Ϊ���ֱ�Ӵ�����������룩ƥ��ģ��л���ֺ����ң���ŵ����
    	int i = 0;
    	while (i < len)
    	{
    		if (s[i] == '(')
    		{
    			stk.push(i);
    			i++;
    		}
    		else
    		{
    			if (stk.empty())//stk����ֻ��棨��Ӧ��index�����Բ���棩��Ӧ��index
    				i++;
    			else
    			{
    				flag[stk.top()] = true;
    				flag[i] = true;
    				stk.pop();
    				i++;
    			}
    		}
    	}
    	for (int i = 0; i < len; i++)
    		cout<<flag[i]<<" ";
    	int result = 0;
    	int temp = 0;
    	for (int i = 0; i < len; i++)
    	{
    		if (flag[i] == true)
    		{
    			temp++;
    			result = temp>result?temp:result;
    		}
    		else
    		{
    			result = temp>result?temp:result;
    			temp = 0;
    		}
    	}
    	return result;
    }
};
/*int main(){
	string s = "(()()";
	Solution t;
	cout<<t.longestValidParentheses(s);
	return 0;
}
**/
