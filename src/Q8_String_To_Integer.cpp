#include<iostream>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
    	int num_len = 0;
    	int result = 0;
    	int flag = 0;
    	int ornot = 0;//标记目前为止还没出现数字
    	for (int i=0; i<str.length(); i++){
    		if (str[i]-'0' >= 0 && str[i]-'0' <= 9){
    			num_len++;
    			ornot = 1;
    		}else{
    			if (str[i]-'-' == 0 && ornot == 0 && flag == 0)
    				flag = 1;
    			else if (str[i]-'+' == 0 && ornot == 0 && flag == 0)
    				flag = 2;
    			else if (str[i]-' ' == 0 && flag == 0 && ornot == 0)
    				continue;
    			else
    				break;
    		}
    	}
    	//cout<<num_len<<endl;
    	int num = 1;
    	for (int i=0; i<str.length(); i++){
    		if (str[i]-'0' >= 0 && str[i]-'0' <= 9 && num <= num_len){
    			if (INT_MAX-result < int(str[i]-'0')*int(pow(10,num_len-num)))
    				return (flag==1)?INT_MIN:INT_MAX;
    			result = result + int(str[i]-'0')*int(pow(10,num_len-num));
    			num++;
    		}
    		if (num == num_len+1)
    			break;
    	}
        return (flag==1)?(0-result):result;
    }
};
int main(){
	string str = "  -23fwdfg";
	Solution s;
	int i = s.myAtoi(str);
	cout<<i;
	return 0;
}
