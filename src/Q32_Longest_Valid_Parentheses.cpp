#include<iostream>
#include<string>
#include<stack>
#include<cstring>//memset的头文件
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
    	int len = s.length();
    	if (len < 2)
    		return 0;
    	bool *flag = new bool[len];//申请长为len的数组，来存储这个数是否构成了匹配的符号
    	memset(flag,false,len);//初始化都为false
    	stack<int> stk;
    	//stack里面存的是可能配对的符号的index，
    	//之所以这样是因为如果直接存入符号在找与）匹配的（中会出现很难找（序号的情况
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
    			if (stk.empty())//stk里面只会存（对应的index，绝对不会存）对应的index
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
