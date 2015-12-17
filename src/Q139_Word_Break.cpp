#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
/**
 * ��ʱ����������������������������������������
 * class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	if (s == "")
    		return true;
    	if (wordDict.size() == 0)
    		return false;
    	if (wordDict.find(s) != wordDict.end())
    		return true;
    	return dfs_find(s,0,wordDict);
    }
    bool dfs_find(string s, int begin, unordered_set<string>& wordDict)
    {
    	if (begin == s.length())
    		return true;
    	for (int i = 1; i <= s.length()-begin; i++)
    	{
    		if (wordDict.find(s.substr(begin,i)) != wordDict.end() && dfs_find(s,begin+i,wordDict))
    			return true;
    	}
    	return false;
    }
};
**/
/**
 * ��ȷ����������������������������
 * class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        //��̬�滮
    	vector<bool> f(s.length()+1,false);//���i���ָ��֮ǰ�����ǲ��Ǵ��ڣ�i=0��""�������i=s.length()��s�����
    	f[0] = true;
    	for (int i = 0; i < s.length(); i++)
    	{
    		for (int j = i; j >= 0; j--)
    		{
    			if (f[j] && wordDict.find(s.substr(j,i-j+1)) != wordDict.end())
    			{
    				f[i+1] = true;
    				break;
    			}
    		}
    	}
    	return f[s.length()];
    }
};
**/
