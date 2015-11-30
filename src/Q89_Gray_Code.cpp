#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
 * 正确答案非得用不正常的顺便来排格雷码！！！！！无语！！！！！！！
class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> result;
    	int sum = 0;
    	result.push_back(sum);
    	if (n == 0)
    		return result;
    	for (int i = 0; i < n; i++)
    	{
    		sum += int(pow(2,i));
    		result.push_back(sum);
    	}
    	for (int i = n-2; i >=0 ;i--)
    	{
    		sum -= int(pow(2,i));
    		result.push_back(sum);
    	}
    	for (int i = 1; i < n-1; i++)
    	{
    		sum += int(pow(2,i));
    		result.push_back(sum);
    	}
    	for (int i = n-1; i > 1; i--)
    	{
    		sum -= int(pow(2,i));
    		result.push_back(sum);
    	}
    	return result;
    }
};
**/
class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> result;
    	result.push_back(0);
    	for (int i = 0; i < n; i++)
    	{
    		int add = int(pow(2,i));
    		for (int i = result.size()-1; i >= 0; i--)
    			result.push_back(result[i]+add);
    	}
    	return result;
    }
};
/**int main(){
	int n = 3;
	Solution s;
	vector<int> result = s.grayCode(n);
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";
	return 0;
}
**/
