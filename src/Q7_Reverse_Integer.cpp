#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
    	int x1 = x;	//��¼�м����
    	int out = 0;	//��¼����ֵ
    	int len  = 1;
    	int flag = 0;	//Ĭ������������Ϊ0
    	if (x<0)
    		flag = 1;	//���Ǹ�������Ϊ1,������Ϊ�˷��㸺�������ж��Ƿ�Խ��
    	while(x1/10){	//��¼intλ��
    		x1 = x1/10;
    		len++;
    	}
    	if (len == 1)
    		return x;
    	if (x<0)
    		x = abs(x);
    	int index_new = 0;
    	while(len-- && len >= 0){
    		int temp1 = x/int(pow(10,len));//����ԭint�������
    		if(index_new == 9 && temp1 > 2)//������������Խ�磬ֱ�ӷ���0
    			return 0;
    		int temp2 = temp1*int(pow(10,index_new));//���������Ӧ���ۼӵ�ֵ
    		if (INT_MAX - out < temp2)//�ж��Ƿ��Խ��
    			return 0;
    		out = out + temp2;
    		x = x%int(pow(10,len));//������һ�������������
    		index_new++;
    	}
    	if (flag == 1)
    		out = 0-out;
    	return out;
    }
};
//-----------------ע��--------------------
//---------pow(x,y)���ص�ֵ��double���͵�-------
/**int main(){
	int x = 123;
	Solution s;
	cout<<s.reverse(x);
	return 0;
}
**/
