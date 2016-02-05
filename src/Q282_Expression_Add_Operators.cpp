#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
	vector<string>result;
    vector<string> addOperators(string num, int target) {
    	if (num == "")
    		return result;
    	string res;
    	addO(num,target,0,0,res);
    	return result;
    }
    void addO(string num, long long target, long long sum, long long prenum, string res)
    {
    	if (num.length() == 0 && sum == target)
    	{
    		result.push_back(res);
    	}
    	else
    	{
    		for (int i = 0; i < num.length(); i ++)
    		{
    			string cur = num.substr(0,i+1);
    			if (cur.length() > 1 && cur[0] == '0')//出现0开头的数，直接pass
    				return;
    			long long temp = str2int(cur);
    			string nnum = num.substr(i+1);
    			if (res.length() == 0)//开头的数
    			{
    				addO(nnum,target,temp,temp,cur);
    			}
    			else
    			{
    				addO(nnum,target,sum+temp,temp,res+"+"+cur);
    				addO(nnum,target,sum-temp,-temp,res+"-"+cur);
    				addO(nnum,target,(sum-prenum)+temp*prenum,temp*prenum,res+"*"+cur);
    			}
    		}
    	}
    }
    long long str2int(string num)
    {
    	stringstream ss;
    	ss<<num;
    	long long r;
    	ss>>r;
    	return r;
    }
};
