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
    			if (i == 0) //��һ�У�ֻҪ���ֹ�1����ô�����temp�ж�Ӧ����0
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
    			else if (j != 0) //��������ߣ�j = 0��Ҫά��ԭ״���൱�ڵ�һ��ֻҪ����0�������temp[0]��������0
    			{
    				temp[j] = temp[j-1]+temp[j];
    			}
    		}
    	}
    	return temp[n-1];
    }
};
