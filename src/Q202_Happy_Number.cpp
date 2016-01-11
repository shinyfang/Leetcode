#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
    	vector<int> f;
    	while (find(f.begin(),f.end(),n) == f.end())
    	{
    		int temp = 0;
    		f.push_back(n);
    		while (n != 0)
    		{
    			temp += pow(n%10,2);
    			n /= 10;
    		}
    		if (temp == 1)
    			return true;
    		n = temp;
    	}
    	return false;
    }
};
