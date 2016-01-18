#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> r;
    	if (nums.size() == 0)
    		return r;
    	int start = nums[0];
    	int end = nums[0];
    	for (int i = 1; i < nums.size(); i ++)
    	{
    		if (nums[i] == end || nums[i] == (end + 1))
    			end ++;
    		else
    		{
    			string res = int2str(start);
    			if (start != end)
    				res += ("->"+int2str(end));
    			r.push_back(res);
    			start = end = nums[i];
    		}
    	}
    	string res = int2str(start);
    	if (start != end)
    		res += ("->"+int2str(end));
    	r.push_back(res);
    	return r;
    }
    string int2str(int a)
    {
    	stringstream ss;
    	ss<<a;
    	string r;
    	ss>>r;
    	return r;
    }
};
