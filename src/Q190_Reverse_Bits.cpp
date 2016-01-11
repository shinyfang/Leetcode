#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
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
/**int main(){
	uint32_t n = 43261596;
	Solution s;
	cout<<s.reverseBits(n);
	return 0;
}
**/
