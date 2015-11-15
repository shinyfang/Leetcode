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
    	if (n < 0)//ע��int_maxҪ���ǵ���������
    	{
    		if (n == INT_MIN)
    			return 1.0/(myPow(x,INT_MAX)*x);
    		return 1.0/myPow(x,-n);
    	}
    	if (n == 1) //���ǵݹ�����һ��
    		return x;
    	double half = myPow(x,n/2); //ʵ�ֶ����half�����ں����õ�half
    	//�ݹ�
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
