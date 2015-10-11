#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
    	//不能连续出现三个相同的字母，所以要单独考虑4 9以及它们的10 100倍
    	string result;
    	while(num){
    		if (num/1000){
    			result.append("M");
    			num = num-1000;
    		}
    		else if (num/900){
    			result.append("CM");
    			num = num-900;
    		}
    		else if (num/500){
    			result.append("D");
    			num = num-500;
    		}
    		else if (num/400){
    			result.append("CD");
    			num = num-400;
    		}
    		else if (num/100){
    			result.append("C");
    			num = num-100;
    		}
    		else if (num/90){
    			result.append("XC");
    			num = num-90;
    		}
    		else if (num/50){
    			result.append("L");
    			num = num-50;
    		}
    		else if (num/40){
    			result.append("XL");
    			num = num-40;
    		}
    		else if (num/10){
    			result.append("X");
    			num = num-10;
    		}
    		else if (num/9){
    			result.append("IX");
    			num = num-9;
    		}
    		else if (num/5){
    			result.append("V");
    			num = num-5;
    		}
    		else if (num/4){
    			result.append("IV");
    			num = num-4;
    		}
    		else{
    			result.append("I");
    			num = num-1;
    		}
    	}
    	return result;
    }
};

/**int main(){
	Solution s;
	int num = 3999;
	cout<<s.intToRoman(num);
	return 0;
}
**/
