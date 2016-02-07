#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	if (pattern == "")
    		return true;
    	int p1 = 0;
    	int p2 = 0;
    	map<char,string> m1;
    	map<string,char> m2;//“ª“ª”≥…‰
    	while (p1 < pattern.length() && p2 < str.length())
    	{
    		while (str[p2] == ' ' && p2 < str.length())
    			p2 ++;
    		if (p2 == str.length())
    			break;
    		char p = pattern[p1];
    		int begin = p2;
    		int len = 0;
    		while (str[p2] != ' ' && p2 < str.length())
    		{
    			len ++;
    			p2 ++;
    		}
    		string s = str.substr(begin,len);
    		if (m1.find(p) != m1.end())
    		{
    			if (m2.find(s) != m2.end() && m2[s] == p)
    			{
    				p1 ++;
    				continue;
    			}
    			return false;
    		}
    		else
    		{
    			if (m2.find(s) == m2.end())
    			{
    				m1[p] = s;
    				m2[s] = p;
    				p1 ++;
    				continue;
    			}
    			return false;
    		}
    	}
    	if (p1 == pattern.length() && p2 == str.length())
    		return true;
    	return false;
    }
};
