#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
    	if (matrix.size() == 0)
    		return 0;
    	int n = matrix.size();
    	int m = matrix[0].size();
    	vector<vector<int> > f(n,vector<int>(m,0));
    	int r = 0;
    	for (int i = 0; i < m; i ++)
    	{
    		f[n-1][i] = matrix[n-1][i] - '0';
    		r = f[n-1][i]>r?f[n-1][i]:r;
    	}
    	for (int i = 0; i < n; i ++)
    	{
    		f[i][m-1] = matrix[i][m-1] - '0';
    		r = f[i][m-1]>r?f[i][m-1]:r;
    	}
    	for (int i = n-2; i >= 0; i --)
    	{
    		for (int j = m - 2; j >= 0; j --)
    		{
    			if (matrix[i][j] == '0')
    				f[i][j] = 0;
    			else
    			{
    				if (f[i][j+1] > 0 && f[i+1][j] > 0 && f[i+1][j+1] > 0)
    					f[i][j] = min(f[i][j+1],f[i+1][j],f[i+1][j+1]) + 1;//这里必须是三者最小的值
    				else
    					f[i][j] = 1;
    			}
    			r = f[i][j]>r?f[i][j]:r;
    		}
    	}
    	return pow(r,2);
    }
    int min(int a, int b, int c)
    {
    	int r = a;
    	r = r < b ? r : b;
    	r = r < c ? r : c;
    	return r;
    }
};
/**int main(){
	vector<vector<char> > matrix;
	vector<char> v1;
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('1');
	matrix.push_back(v1);
	vector<char> v2;
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('0');
	matrix.push_back(v2);
	vector<char> v3;
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('0');
	matrix.push_back(v3);
	vector<char> v4;
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('0');
	v4.push_back('0');
	v4.push_back('0');
	matrix.push_back(v4);
	vector<char> v5;
	v5.push_back('0');
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('0');
	v5.push_back('0');
	v5.push_back('0');
	matrix.push_back(v5);
	Solution s;
	cout<<s.maximalSquare(matrix);
	return 0;
}
**/
