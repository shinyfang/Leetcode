#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	int m = matrix.size();
    	int n = matrix[0].size();
    	if (m == 0 || n == 0 || target < matrix[0][0] || target > matrix[m-1][n-1])
    		return false;
    	int x = 0;
    	int y = n - 1;
    	while (x >= 0 && x < m && y >= 0 && y < n)
    	{
    		if (matrix[x][y] == target)
    			return true;
    		else if (matrix[x][y] < target)
    			x ++;
    		else
    			y --;
    	}
    	return false;
    }
};
