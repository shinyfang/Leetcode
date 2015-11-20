#include<iostream>
using namespace std;
class Solution {//递归会超时！！！！！！！！！！！！！！！
public:
    int climbStairs(int n) {
    	int pre = 1;//记录前一次结果
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
