#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
    	if (num1 == "0" || num2 == "0")
    		return "0";
    	//按照乘法步骤，注意进位，a位数和b位数相乘结果最大的位数是a+b
    	string result(num1.length()+num2.length(),'0');
    	for (int i = num1.length()-1; i >= 0 ; i--)
    	{
    		int a = num1[i]-'0';
    		for (int j = num2.length()-1; j >= 0; j--)
    		{
    			int k = i+j+1;
    			int b = num2[j]-'0';
    			int c = a*b + (result[k]-'0');//各个位上相乘，加上进位
    			result[k] = c%10 + '0';
    			result[k-1] = c/10 + (result[k-1]-'0') + '0';//注意这里要加上前一位本身就有的数
    		}
    	}
    	if (result[0] == '0')
    		return result.substr(1);
    	else
    		return result;
    }
};
/**int main(){
	string num1 = "99";
	string num2 = "900";
	Solution s;
	string result = s.multiply(num1,num2);
	for (int i = 0; i < result.length(); i++)
		cout<<result[i];
	return 0;
}
**/
