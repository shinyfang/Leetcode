#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
    	int x1 = x;	//记录中间变量
    	int out = 0;	//记录返回值
    	int len  = 1;
    	int flag = 0;	//默认是正数，记为0
    	if (x<0)
    		flag = 1;	//若是负数，记为1,这样是为了方便负数后面判断是否越界
    	while(x1/10){	//记录int位数
    		x1 = x1/10;
    		len++;
    	}
    	if (len == 1)
    		return x;
    	if (x<0)
    		x = abs(x);
    	int index_new = 0;
    	while(len-- && len >= 0){
    		int temp1 = x/int(pow(10,len));//计算原int上这个数
    		if(index_new == 9 && temp1 > 2)//如果这个数可能越界，直接返回0
    			return 0;
    		int temp2 = temp1*int(pow(10,index_new));//计算这个数应该累加的值
    		if (INT_MAX - out < temp2)//判断是否会越界
    			return 0;
    		out = out + temp2;
    		x = x%int(pow(10,len));//更新下一次用来计算的数
    		index_new++;
    	}
    	if (flag == 1)
    		out = 0-out;
    	return out;
    }
};
//-----------------注意--------------------
//---------pow(x,y)返回的值是double类型的-------
/**int main(){
	int x = 123;
	Solution s;
	cout<<s.reverse(x);
	return 0;
}
**/
