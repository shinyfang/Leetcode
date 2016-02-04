#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
    	if (n == 1)
    		return 1;
    	vector<int> res;
    	res.push_back(1);
    	int x1 = 0;
    	int x2 = 0;
    	int x3 = 0;
    	//¼ÇÂ¼*2 *3 *5µÄindex
    	while (res.size() < n)
    	{
    		res.push_back(min(res[x1]*2,res[x2]*3,res[x3]*5));
    		while (res[x1]*2 <= res[res.size()-1])
    			x1 ++;
    		while (res[x2]*3 <= res[res.size()-1])
    			x2 ++;
    		while (res[x3]*5 <= res[res.size()-1])
    			x3 ++;
    	}
    	return res[res.size()-1];
    }
    int min(int a, int b, int c)
    {
    	int max = a<b?a:b;
    	max = max<c?max:c;
    	return max;
    }
};
