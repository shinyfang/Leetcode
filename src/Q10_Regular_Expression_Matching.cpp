#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
    	if (s == "" && p == "")
    		return true;
    	if (p == "")
    		return false;
    	return match(s,0,p,0);
    }
    bool match(string s, int i, string p, int j)
    {
    	if (i == s.length() && j == p.length())
    		return true;
    	if (j == p.length())
    		return false;
    	if (p[j+1] == '*')
    	{
    		while ((i < s.length() && p[j] == '.') || s[i] == p[j])
    		{
    			if (match(s,i,p,j+2))
    				return true;
    			i++;
    		}
    		//如果s[i]!=p[j]直接忽略p[j]和p[j+1]即可
    		return match(s,i,p,j+2);
    	}
    	else
    	{
    		if (p[j] == '.' || s[i] == p[j])
    			return match(s,i+1,p,j+1);
    		else
    			return false;
    	}
    	return false;
    }
};
/**int main(){
	Solution t;
	string s = "aaaaaaaaaaaaab";
	string p = "a*a*a*a*a*a*a*a*a*a*a*a*b";
	cout<<t.isMatch(s,p);
	return 0;
}
**/
