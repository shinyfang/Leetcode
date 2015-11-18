#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	vector<int> temp(n,1);
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (i == 0) //第一行，只要出现过1，那么后面的temp中都应该是0
    			{
    				if (j == 0 && obstacleGrid[i][j] == 1)
    					return 0;
    				else if (j == 0 && obstacleGrid[i][j] != 1)
    					temp[j] = 1;
    				else
    				{
    					if (obstacleGrid[i][j] == 1)
    						temp[j] = 0;
    					else
    						temp[j] = temp[j-1];
    				}
    			}
    			else if (obstacleGrid[i][j] == 1)
    			{
    				temp[j] = 0;
    			}
    			else if (j != 0) //如果可以走，j = 0处要维持原状，相当于第一列只要出现0，后面的temp[0]都必须是0
    			{
    				temp[j] = temp[j-1]+temp[j];
    			}
    		}
    	}
    	return temp[n-1];
    }
};
