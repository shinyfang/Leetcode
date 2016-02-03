#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
/**class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s == "" && t == "")
    		return true;
    	if (s == "" && t == "")
    		return false;
    	sort(s.begin(),s.end());
    	sort(t.begin(),t.end());
    	return s==t?true:false;
    }
};
**/
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s == "")
    		return t=="";
    	if (t == "")
    		return s=="";
    	map<char,int> m;
    	for (int i = 0; i < s.length(); i ++)
    	{
    		if (m.find(s[i]) != m.end())
    			m[s[i]] ++;
    		else
    			m[s[i]] = 1;
    	}
    	for (int i = 0; i < t.length(); i ++)
    	{
    		if (m.find(t[i]) == m.end() || (m[t[i]] == 0))
    			return false;
    		else
    			m[t[i]] --;
    	}
    	for (int i = 0; i < m.size(); i ++)
    	{
    		if (m[i] != 0)
    			return false;
    	}
    	return true;
    }
};
