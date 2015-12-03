#include<iostream>
#include<vector>
#include<string>
using namespace std;
/**
 *超时！！！！！！！！！！！！！
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if (s1.length() + s2.length() != s3.length())
    		return false;
    	if (s3 == "")
    		return true;
    	return Intlv(s1,0,s2,0,s3,0);
    }
    bool Intlv(string s1, int p1, string s2, int p2, string s3, int p3)
    {
    	cout<<"s1="<<s1[p1]<<" s2="<<s2[p2]<<" s3="<<s3[p3]<<endl;
    	if (p1 == s1.length() && p2 == s2.length() && p3 == s3.length())
    		return true;
    	if (p1 == s1.length())
    	{
    		for (int j = p2; j < s2.length(); j++)
    		{
    			if (s2[j] != s3[p3])
    				return false;
    			p3 ++;
    		}
    		return true;
    	}
    	if (p2 == s2.length())
    	{
    		for (int j = p1; j < s1.length(); j++)
    		{
    			if (s1[j] != s3[p3])
    				return false;
    			p3 ++;
    		}
    		return true;
    	}
    	if (s1[p1] == s3[p3] && s2[p2] != s3[p3])
    		return Intlv(s1,p1+1,s2,p2,s3,p3+1);
    	if (s2[p2] == s3[p3] && s1[p1] != s3[p3])
    		return Intlv(s1,p1,s2,p2+1,s3,p3+1);
    	if (s1[p1] == s3[p3] && s2[p2] == s3[p3])
    	{
    		if (Intlv(s1,p1+1,s2,p2,s3,p3+1))
    			return true;
    		else
    			return Intlv(s1,p1,s2,p2+1,s3,p3+1);
    	}
    }
};
**/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	//二维动态规划
    	if (s1.length() + s2.length() != s3.length())
    		return false;
    	int m = s1.length();
    	int n = s2.length();
    	vector<vector<bool> > flag(m+1,vector<bool>(n+1,false));
    	for (int i = 0; i <= m; i++)
    	{
    		for (int j = 0; j <= n; j++)
    		{
    			if (i == 0 && j == 0)
    				flag[i][j] = true;
    			else if (i == 0)
    			{
    				flag[i][j] = flag[i][j-1] & (s2[j-1] == s3[j-1]);//只有当左边==1和当前两字符相同才写true
    			}
    			else if (j == 0)
    			{
    				flag[i][j] = flag[i-1][j] & (s1[i-1] == s3[i-1]);
    			}
    			else
    			{
    				flag[i][j] = (flag[i][j-1] & s2[j-1] == s3[i+j-1]) || (flag[i-1][j] & s1[i-1] == s3[i+j-1]);
    			}
    		}
    	}
    	return flag[m][n];
    }
};
/**int main(){
	string s1 = "";
	string s2 = "";
	string s3 = "";
	Solution s;
	cout<<s.isInterleave(s1,s2,s3);
	return 0;
}

**/
