#include<iostream>
#include<vector>
using namespace std;
//埃拉托斯特尼筛法，找素数的方法
class Solution {
public:
    int countPrimes(int n) {
    	if (n <= 2)//小于n的素数
    		return 0;
    	vector<bool> f(n-1,true);//小于n，不包括n
    	f[0] = false;
    	for (int i = 2; i*i < n; i++)
    	{
    		if (f[i-1] == false)
    			continue;
    		for (int j = i*i; j < n; j+=i)//i的倍数相当于以i为公差的等差序列，并且要从i^2起判断，因为i是素数
    			f[j-1] = false;
    	}
    	int r = 0;
    	for (int i = 0; i < f.size(); i++)
    		r += f[i]==true?1:0;
    	return r;
    }
};
