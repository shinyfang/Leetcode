#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	vector<string> r;
	int maxlen;
    vector<string> removeInvalidParentheses(string s) {
    	vector<string> result;
    	maxlen = 0;
    	reIn(s,0,"",0);
    	map<string,int> m;
    	for (vector<string>::iterator it = r.begin(); it != r.end(); it ++)
    	{
    		if (m.find(*it) == m.end())
    		{
    			result.push_back(*it);
    			m[*it] = 1;
    		}
    	}
    	return result;
    }
    void reIn(string s, int begin, string res, int left)//res���Ѿ��ж��ٸ�������
    {
    	if (begin == s.length())
    	{
    		if (left == 0 && res.length() >= maxlen)
    		{
    			//left==0˵���������Ŷ��Գ���
    			if (res.length() > maxlen)
    			{
    				r.clear();
    				maxlen = res.length();
    			}
    			r.push_back(res);
    		}
    		return;
    	}
    	if (s[begin] == '(')
    	{
    		reIn(s,begin+1,res+"(",left+1);
    		reIn(s,begin+1,res,left);
    	}
    	else if (s[begin] == ')')
    	{
    		if (left == 0)
    			reIn(s,begin+1,res,left);
    		else
    		{
    			reIn(s,begin+1,res+")",left-1);
    			reIn(s,begin+1,res,left);
    		}
    	}
    	else
    	{
    		reIn(s,begin+1,res+s[begin],left);
    	}
    }
};
