#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<int> temp(n,1);
    	m--;
    	while (m--)
    	{
    		for (int i = 1; i < n; i++)
    			temp[i] = temp[i-1]+temp[i];//�൱��ÿ������ߺ�����������
    	}
    	return temp[n-1];
    }
};
/**int main()
{
	int m = 3;
	int n = 3;
	Solution s;
	cout<<s.uniquePaths(m,n);
	return 0;
}
**/
