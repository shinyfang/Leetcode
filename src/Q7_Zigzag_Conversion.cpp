#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	string out;
    	int len = s.length();
    	int k1 = 0;
    	if (numRows == 1)//���ֻ��һ�У�ֱ�ӷ���
    		return s;
    	if (numRows > len)//����д����ַ����ĳ��ȣ�Ҳֱ�ӷ���
    		return s;
    	while((k1*(numRows-1)*2)<len){ //��һ�е�������
    		out.append(1,s[k1*(numRows-1)*2]);
    		k1++;
    	}
    	for(int i = 1; i < numRows-1; i++){//����һ�к����һ�У��м�Ĺ���
    		int k2 = 0;
    		while ( ((k2*(numRows-1))*2+i) <len){
    			out.append(1,s[k2*(numRows-1)*2 + i]);
    			if (((k2*(numRows-1)+(numRows-i-1))*2+i) <len){
    				out.append(1,s[(k2*(numRows-1)+(numRows-i-1))*2+i]);
    			}
    			k2++;
    		}
    	}
    	int k3 = 0;
    	while((k3*(numRows-1)*2 + numRows - 1)<len){//���һ�е�������
    		out.append(1,s[k3*(numRows-1)*2 + numRows - 1]);
    		k3++;
    	}
    	return out;
    }
};
/**int main(){
	string s = "ABc";
	Solution t;
	cout<<t.convert(s,3);
	return 0;
}
**/
