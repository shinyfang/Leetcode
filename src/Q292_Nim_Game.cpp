#include<iostream>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
    	//逢4和4的倍数就会输
    	return n%4!=0;
    }
};
