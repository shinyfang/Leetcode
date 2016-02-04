#include<iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
    	//ÕÒ¹æÂÉ
    	return (num-1)%9+1;
    }
};
