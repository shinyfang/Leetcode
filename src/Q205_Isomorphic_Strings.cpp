#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s == "")
    		return true;
    	//��map����¼��Ӧ��ϵ����Ϊֻ����һһ��Ӧ�����Խ������αȽ�
    	map<char,char> m;
    	for (int i = 0; i < s.length(); i++)
    	{
    		if (m.find(s[i]) != m.end())
    		{
    			if (m[s[i]] != t[i])
    				return false;
    		}
    		else
    			m[s[i]] = t[i];
    	}
    	m.clear();
    	for (int i = 0; i < t.length(); i++)
    	{
    		if (m.find(t[i]) != m.end())
    		{
    			if (m[t[i]] != s[i])
    				return false;
    		}
    		else
    			m[t[i]] = s[i];
    	}
    	return true;
    }
};
