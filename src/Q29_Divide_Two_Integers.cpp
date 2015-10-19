#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
/**
 * ���̫���ţ������ó˳��࣬���õĳ��˼Ӽ�����λ���㣡������������
 * class Solution {
public:
    int divide(int dividend, int divisor) {
    	if (dividend < divisor)
    		return 0;
    	int flag1 = 0;
    	int flag2 = 0;
    	if (dividend <= 0)
    	{
    		flag1 = 1;
    		dividend = abs(dividend);
    	}
    	if (divisor <= 0)
    	{
    		flag2 = 1;
    		divisor = abs(divisor);
    	}
    	int result = 0;
    	int temp = 0;
    	while(temp <= dividend)
    	{
    		if (result == INT_MAX)
    			return INT_MAX;
    		temp += divisor;
    		result++;
    	}
    	if (flag1 == flag2)
    		return (result-1);
    	else
    		return 0-(result-1);
    }
};
**/
class Solution {
public:
   int divide(int dividend, int divisor) {
	   if (divisor == 0)
		   return INT_MAX;
	   //Ҫ����INT_MIN�����ֱ��abs(INT_MIN)�����
	   int flag1 = 0;
	   int flag2 = 0;//Ĭ��Ϊ����
	   long long a = (long long) dividend;
	   long long b = (long long) divisor;//��abs�����
	   if (dividend < 0)
	   {
		   flag1 = 1;
		   a = abs(a);
	   }
	   if (divisor < 0)
	   {
		   flag2 = 1;
		   b = abs(b);
	   }
	   cout<<a<<" "<<b<<endl;
	   if (a < b || a == 0)//����������������ֵС�ڳ�������ֵ���߱�����==0
		   return 0;
	   if (a == b)//����������
		   return (flag1==flag2?1:-1);
	   if (a <= INT_MAX && b == 1)//����Ϊ1������ֱ�ӷ��ر���������Ҫ��������������
		   return (flag1==flag2?a:-a);
	   if (a >INT_MAX && b == 1)
		   return (flag1==flag2?INT_MAX:INT_MIN);
	   int result = 0;
	   while (a >= b)
	   {
		   long long temp = b;//�������Ҫ�仯
		   int temp2 = 1;
		   while (a >= (temp<<1))
		   {
			   temp = temp<<1;
			   temp2 = temp2<<1;
		   }
		   cout<<"b:"<<temp<<endl;
		   result += temp2;
		   a = a-temp;
		   cout<<"a:"<<a<<endl;
	   }
	   return (flag1==flag2?result:-result);
   }
};
/**int main(){
	Solution s;
	int dividend = -105;
	int divisor = 2;
	cout<<s.divide(dividend,divisor);
	return 0;
}
**/
