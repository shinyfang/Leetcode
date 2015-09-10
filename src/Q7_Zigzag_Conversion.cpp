#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	string out;
    	int len = s.length();
    	int k1 = 0;
    	if (numRows == 1)//如果只有一列，直接返回
    		return s;
    	if (numRows > len)//如果列大于字符串的长度，也直接返回
    		return s;
    	while((k1*(numRows-1)*2)<len){ //第一行单独讨论
    		out.append(1,s[k1*(numRows-1)*2]);
    		k1++;
    	}
    	for(int i = 1; i < numRows-1; i++){//除第一行和最后一行，中间的规律
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
    	while((k3*(numRows-1)*2 + numRows - 1)<len){//最后一行单独讨论
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
