#include<iostream>
using namespace std;
/**class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if (n == 0)
    		return false;
    	if (n == 1)
    		return true;
    	int i = 2;
    	while (n/i)
    	{
    		if (n%i != 0)
    			return false;
    		n /= i;
    		i = i<<1;
    	}
    	isPowerOfTwo(n);
    }
};
**/
//二进制表示的话只有一位是1，n-1会使得其他位都为1，与的结果是0
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	return (n > 0) && ((n & (n - 1)) == 0);
    }
};
