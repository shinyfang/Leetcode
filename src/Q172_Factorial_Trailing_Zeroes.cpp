#include<iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
    	//有5肯定就有2或者2的倍数，就可能形成一个0
    	//同样5的倍数也能与2的倍数形成0
    	//并且5的倍数肯定是小于2的倍数，所以所有的5以及5的倍数都算作一个0
    	int result = 0;
    	while (n >= 5)
    	{
    		result += n/5;
    		n /= 5;
    	}
    	return result;
    }
};
