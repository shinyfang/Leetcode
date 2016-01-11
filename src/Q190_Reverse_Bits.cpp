#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	vector<bool> f(32,false);
    	uint32_t i = 31;
    	while (n > 0)
    	{
    		if (n >= pow(2,i))
    		{
    			f[i] = true;
    			n -= pow(2,i);
    		}
    		i --;
    	}
    	i = 0;
    	for (int k = 0; k < 32; k ++)
    		i += f[k]==true?pow(2,31-k):0;
    	return i;
    }
};
**/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	uint32_t r = 0;
    	for (int i = 0; i < 32; i ++)//为什么不能直接判断n>0
    	{
    		r = (r << 1) | (n & 1);//每次得到原二进制的最后一位，累加到result上去
    		n >>= 1;
    	}
    	return r;
    }
};
/**int main(){
	uint32_t n = 43261596;
	Solution s;
	cout<<s.reverseBits(n);
	return 0;
}
**/
