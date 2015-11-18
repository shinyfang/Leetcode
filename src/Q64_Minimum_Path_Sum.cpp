#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
    	int m = grid.size();
    	int n = grid[0].size();
    	vector<int> temp(n,0);
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (i == 0 && j == 0)
    				temp[j] = grid[i][j];
    			else if (i == 0)
    				temp[j] = temp[j-1]+grid[i][j];
    			else if (j == 0)
    				temp[j] += grid[i][j];
    			else
    				temp[j] = temp[j-1]<temp[j]?(temp[j-1]+grid[i][j]):(temp[j]+grid[i][j]);
    		}
    	}
    	return temp[n-1];
    }
};
