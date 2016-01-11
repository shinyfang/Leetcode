#include<iostream>
#include<cmath>
using namespace std;
/**class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	int r = 0;
    	int i = 31;
    	while (m > 0)
    	{
    		if (pow(2,i) <= m)
    		{
    			r += pow(2,i);
    			m -= pow(2,i);
    			n -= pow(2,i);
    		}
    		else if (pow(2,i) > m && pow(2,i) <= n)
    			return r;
    		i --;
    	}
    	return r;
    }
};
**/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	int r = 0;
    	int p = 0;//记录结果移位情况
    	while (m > 0)//没有找到相同的部分
    	{
    		if (m == n)//找到相同的部分，说明前面都不用比较了，但是记得移位
    			return m<<p;
    		m >>= 1;
    		n >>= 1;
    		p ++;
    	}
    	return r<<p;
    }
};
/**int main(){
	int m = 5;
	int n = 7;
	Solution s;
	cout<<s.rangeBitwiseAnd(m,n);
	return 0;
}
**/
