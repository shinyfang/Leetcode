#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
class Solution {
public:
	static bool comp179(const string& a, const string& b)
	{
		return a+b>b+a;
	}
    string largestNumber(vector<int>& nums) {
    	string result;
    	vector<string> number;
    	for (int i = 0; i < nums.size(); i++)
    		number.push_back(int2str(nums[i]));
    	sort(number.begin(),number.end(),comp179);
    	for (int i = 0; i < number.size(); i++)
    		result += number[i];
    	if (result[0] == '0')
    		return "0";
    	return result;
    }
    string int2str(int i)
    {
    	string r;
    	stringstream s;
    	s<<i;
    	s>>r;
    	return r;
    }
};
