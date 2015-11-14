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
    	if (p[j] == '*')
    	{
    		while (p[j] == '*')
    			j++;
    		while (i < s.length())
    		{
    			if (match(s,i,p,j))
    				return true;
    			i++;
    		}
    		return match(s,i,p,j);
    	}
    	else
    	{
    		cout<<"s[i]=="<<s[i]<<" p[j]=="<<p[j]<<endl;
    		if ((i< s.length() && p[j] == '?') || s[i] == p[j])
    			return match(s,i+1,p,j+1);
    		else
    			return false;
    	}
    	return false;
    }
};
/**int main(){
	string s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
	string p = "a*******b";
	Solution t;
	cout<<t.isMatch(s,p);
	return 0;
}
**/
