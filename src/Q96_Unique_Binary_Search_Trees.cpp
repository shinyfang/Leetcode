#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
    	//递归会出现重复计算的情况
    	vector<int> f(n+1,0);
    	f[0] = 1;
    	f[1] = 1;
    	for (int i = 2; i <= n; i++)
    	{
    		for (int j = 0; j < i; j++)
    			f[i] += (f[j]*f[i-1-j]);
    	}
    	return f[n];
    }
};
/**int main(){
	int n = 4;
	Solution s;
	cout<<s.numTrees(n);
	return 0;
}
**/
