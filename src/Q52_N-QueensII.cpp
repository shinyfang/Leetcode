#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
    	int result = 0;
    	int *col = new int[n];
    	DFS(result,col,0,n); //col[i]表示当前已确定的第i行Q的列号
    	return result;
    }
    void DFS(int &result, int col[], int deep, int n)
    {
    	if (deep == n)
    	{
    		result += 1;//每次组成一个正确的Queen就加一
    		return;
    	}
    	else
    	{
    		int num = 0;
    		for (int i = 0; i < n; i++)
    		{
    			if (isvalid(col,deep,n,i))
    			{
    				col[deep] = i;
    				DFS(result,col,deep+1,n);
    			}
    		}
    	}
    	return;
    }
    bool isvalid(int col[], int deep, int n, int k)
    {
    	for (int i = 0; i < deep; i++)
    	{
    		if (k == col[i] || (col[i]-i == k-deep) || (col[i]+i == k+deep))
    			return false;
    	}
    	return true;
    }
};
/**int main()
{
	Solution s;
	int n = 4;
	cout<<s.totalNQueens(n);
	return 0;
}
**/
