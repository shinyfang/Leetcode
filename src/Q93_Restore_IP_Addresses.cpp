#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> result;
    	if (s.length() < 4)
    		return result;
    	string res;
    	Ip(result,res,0,0,s);
    	return result;
    }
    void Ip(vector<string>& result, string& res, int start, int step, string s){
    	if (step == 4 && start == s.length())
    	{
    		res = res.substr(0,res.length()-1);//结束，把最后的.去掉
    		result.push_back(res);
    		return;
    	}
    	if (s.length() - start > (4 - step) * 3 || s.length() - start < (4 - step))
    		return;
    	int num = 0;
    	for (int i = start; i < start + 3; i++)
    	{
    		if (i < s.length())
    		{
    			num = 10*num + (s[i]-'0');
				if (num < 256)
				{
					res += s[i];
					string temp = res + '.';
					Ip(result,temp,i+1,step+1,s);
				}
				if ((i == start && s[i] == '0') || num >= 266) //不允许..之间以0开头
					break;
    		}
    		else
    			break;
    	}
    }
};
/**int main()
{
	string t = "0000";
	Solution s;
	vector<string> result = s.restoreIpAddresses(t);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].length(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
**/
