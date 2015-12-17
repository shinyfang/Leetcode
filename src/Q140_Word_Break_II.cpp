#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
/**class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	vector<string> result;
    	if (s == "")
    	{
    		string temp = "";
    		result.push_back(temp);
    		return result;
    	}
    	vector<bool> pre(s.length()+1,false);//来标记i之前的数是否在dict中，不包括i，相当于剪枝
    	pre[0] = true;
    	vector<vector<bool> > f(s.length(), vector<bool>(s.length(),false));
    	for (int i = 0; i < s.length(); i++)
    	{
    		for (int j = i; j >= 0; j--)
    		{
    			if (pre[j] && wordDict.find(s.substr(j,i-j+1)) != wordDict.end())
    			{
    				//找j-i之间的数是否在dict中，看看j之前的数能否分词成功，如果不成功后面就不用继续找了
    				pre[i+1] = true;
    				f[j][i] = true;
    			}
    		}
    	}
    	if (pre[s.length()] == false)//加上这一句就不会超时了！！！！！！
    		return result;
    	vector<string> res;
    	wordPrint(s,result,res,f,0);
    	return result;
    }
    void wordPrint(string& s, vector<string>& result, vector<string> res, vector<vector<bool> >& f, int begin)
    {
    	if (begin == s.length())
    	{
    		string temp;
    		for (int i = 0; i < res.size(); i++)
    			temp += (res[i] + " ");
    		temp = temp.substr(0,temp.length()-1);
    		result.push_back(temp);
    		return;
    	}
    	for (int i = begin; i < s.length(); i++)
    	{
    		if (f[begin][i] == true)
    		{
    			res.push_back(s.substr(begin,i-begin+1));
    			wordPrint(s,result,res,f,i+1);
    			res.pop_back();
    		}
    	}
    }
};
**/
