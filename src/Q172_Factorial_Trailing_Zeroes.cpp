#include<iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
    	//��5�϶�����2����2�ı������Ϳ����γ�һ��0
    	//ͬ��5�ı���Ҳ����2�ı����γ�0
    	//����5�ı����϶���С��2�ı������������е�5�Լ�5�ı���������һ��0
    	int result = 0;
    	while (n >= 5)
    	{
    		result += n/5;
    		n /= 5;
    	}
    	return result;
    }
};
