#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0){
    	    	return false;
    	}//����ֱ���ж�Ϊfalse
    	int temp1 = x;
    	int len = 1;
    	while(temp1/10){
    		temp1 = temp1/10;
    		len++;
    	}
    	if (len == 1)
    		return true;
    	int temp2 = 0;//��¼�ۼӺ��ֵ
    	if (len%2 == 1){//���������λ
    		int temp3 = x;//ÿ����������������ʼֵ��x
    		for(int i = len - 1; i > len/2; i--){
    			int temp4 = temp3/int(pow(10,i));//��λ����
    			temp3 = temp3%int(pow(10,i));
    			if (INT_MAX - temp2 < temp4*int(pow(10,i)))
    				return false;
    			int temp5 = temp2 + temp4*int(pow(10,i));
    			if (INT_MAX - temp5 < temp4*int(pow(10,len-1-i)))
    				return false;
    			temp2 =  temp5 + temp4*int(pow(10,len-1-i));
    		}
    		temp2 = temp2 + int(pow(10,len/2))*(temp3/int(pow(10,len/2)));
    	}else{//�����ż��λ
    		int temp3 = x;//ÿ����������������ʼֵ��x
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
