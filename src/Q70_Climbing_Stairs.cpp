#include<iostream>
using namespace std;
class Solution {//�ݹ�ᳬʱ������������������������������
public:
    int climbStairs(int n) {
    	int pre = 1;//��¼ǰһ�ν��
    	int cur = 1;
    	while (--n)
    	{
    		int newcur = pre+cur;
    		pre = cur;
    		cur = newcur;
    	}
    	return cur;
    }
};
