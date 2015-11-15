#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
    	if (x == 0)
    		return 0;
    	if (n == 0)
    		return 1;
    	if (n < 0)//注意int_max要考虑到！！！！
    	{
    		if (n == INT_MIN)
    			return 1.0/(myPow(x,INT_MAX)*x);
    		return 1.0/myPow(x,-n);
    	}
    	if (n == 1) //这是递归的最后一层
    		return x;
    	double half = myPow(x,n/2); //实现定义好half，便于后面用到half
    	//递归
    	if (n%2 == 0)
    		return half*half;
    	else
    		return half*half*x;
    }
};
/**int main(){
	Solution s;
	double x = 1.1;
	int n = 3;
	cout<<s.myPow(x,n);
	return 0;
}
**/
