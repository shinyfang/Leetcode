#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s) {
    	vector<vector<string> > result;
    	if (s == "")
    		return result;
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
    	vector<string> res;
    	palin_partition(f,s,res,result,0);
    	return result;
    }
    void palin_partition(vector<vector<int> >& f, string& s, vector<string>& res, vector<vector<string> >& result, int start)
    {
    	if (start == s.length())
    	{
    		result.push_back(res);
    		return;
    	}
    	for (int i = start; i < s.length(); i++)
    	{
    		if (f[start][i] == 1)
    		{
    			res.push_back(s.substr(start,i-start+1));
    			palin_partition(f,s,res,result,i+1);
    			res.pop_back();
    		}
    	}
    }
};
/**int main(){
	string s = "a";
	Solution ss;
	vector<vector<string> > result = ss.partition(s);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
**/
