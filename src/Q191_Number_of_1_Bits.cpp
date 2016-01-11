#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
    	if (n == 0)
    		return 0;
    	int r = 0;
    	uint32_t i = 31;
    	while (n > 0)
    	{
    		if (n >= pow(2,i))
    		{
    			r ++;
    			n -= pow(2,i);
    		}
    		i --;
    	}
    	return r;
    }
};
