#include<iostream>
#include<map>
#include<climits>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
    	int *m = new int[n+1];
    	m[0] = 0;
    	for (int i = 1; i <= n; i ++)
    		m[i] = i;
    	for (int i = 2; i <= n; i ++)
    	{
    		for (int j = 1; j*j <= i; j ++)
    		{
    			m[i] = 1+m[i-j*j]<m[i]?1+m[i-j*j]:m[i];
    		}
    	}
    	return m[n];
    }
};
