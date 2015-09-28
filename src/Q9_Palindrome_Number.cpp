#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0){
    	    	return false;
    	}//负数直接判定为false
    	int temp1 = x;
    	int len = 1;
    	while(temp1/10){
    		temp1 = temp1/10;
    		len++;
    	}
    	if (len == 1)
    		return true;
    	int temp2 = 0;//记录累加后的值
    	if (len%2 == 1){//如果是奇数位
    		int temp3 = x;//每次做除法的数，初始值是x
    		for(int i = len - 1; i > len/2; i--){
    			int temp4 = temp3/int(pow(10,i));//高位数字
    			temp3 = temp3%int(pow(10,i));
    			if (INT_MAX - temp2 < temp4*int(pow(10,i)))
    				return false;
    			int temp5 = temp2 + temp4*int(pow(10,i));
    			if (INT_MAX - temp5 < temp4*int(pow(10,len-1-i)))
    				return false;
    			temp2 =  temp5 + temp4*int(pow(10,len-1-i));
    		}
    		temp2 = temp2 + int(pow(10,len/2))*(temp3/int(pow(10,len/2)));
    	}else{//如果是偶数位
    		int temp3 = x;//每次做除法的数，初始值是x
    		for(int i = len - 1; i >= len/2; i--){
    			int temp4 = temp3/int(pow(10,i));
    			temp3 = temp3%int(pow(10,i));
    			if (INT_MAX - temp2 < temp4*int(pow(10,i)))
    				return false;
    			int temp5 = temp2 + temp4*int(pow(10,i));
    			if (INT_MAX - temp5 < temp4*int(pow(10,len-1-i)))
    				return false;
    			temp2 = temp5 + temp4*int(pow(10,len-1-i));
    		}
    	}
    	if (temp2 == x)
    		return true;
    	else
    		return false;
    }
};
/**int main(){
	Solution s;
	int x = 1234321;
	cout<<s.isPalindrome(x);
	return 0;
}
**/
