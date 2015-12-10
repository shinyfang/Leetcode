#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
    	if (t == "")
    		return 1;
    	if (s.length() < t.length())
    		return 0;
    	int len1 = s.length();
    	int len2 = t.length();
    	vector<vector<int> > f(len1 + 1, vector<int>(len2 + 1,0));
    	for (int i = 0; i <= len1; i++)
    		f[i][0] = 1;
    	for (int i = 1; i <= len1; i++)
    	{
    		for (int j = 1; j <= len2; j++)
    		{
    			if (s[i-1] == t[j-1])
    				f[i][j] = f[i-1][j-1] + f[i-1][j];
    			else
    				f[i][j] = f[i-1][j];
    		}
    	}
    	return f[len1][len2];
    }
};
/**int main(){
	string S = "rabbbit";
	string T = "rabbit";
	Solution s;
	cout<<s.numDistinct(S,T);
	return 0;
}
**/
