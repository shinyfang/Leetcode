#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
    	int len = 1;
    	string result;
    	int temp1 = num;
    	while(temp1/10){
    		temp1 = temp1/10;
    		len++;
    	}
    	cout<<"len:"<<len<<endl;
    }
};

/**int main(){
	Solution s;
	int num = 3999;
	s.intToRoman(num);
	return 0;
}
**/
