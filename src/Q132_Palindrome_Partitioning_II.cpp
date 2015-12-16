#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minCut(string s) {
    	if (s.length() < 2)
    		return 0;
    	vector<vector<int> > f(s.length(),vector<int>(s.length(),0));
    	for (int i = s.length() - 1; i >= 0; i--)
    	{
    		for (int j = i; j < s.length(); j++)
    		{
    			if (j == i || (j - i == 1 && s[i] == s[j]))
    				f[i][j] = 1;
    			else
    				f[i][j] = ((s[i] == s[j]) && f[i+1][j-1]);
    		}
    	}
    	vector<int> min(s.length(),0);
    	for (int i = 0; i < s.length(); i++)
    		min[i] = s.length() - i - 1;
    	for (int i = s.length() - 1; i >= 0; i--)
    	{
    		for (int j = i; j < s.length(); j++)
    		{
    			if (f[i][j] == 1)
    			{
    				if (j == s.length() - 1)
    					min[i] = 0;
    				else
    					min[i] = min[j+1]+1<min[i]?(min[j+1]+1):min[i];
    			}
    		}
    	}
    	return min[0];
    }
};
/**int main(){
	string s = "aab";
	Solution ss;
	cout<<ss.minCut(s);
	return 0;
}
**/
