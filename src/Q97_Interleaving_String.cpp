#include<iostream>
#include<string>
using namespace std;
/**
 *³¬Ê±£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
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

    }
};
/**int main(){
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";
	Solution s;
	cout<<s.isInterleave(s1,s2,s3);
	return 0;
}
**/
