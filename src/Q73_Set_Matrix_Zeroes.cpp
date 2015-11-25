#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
    	if (matrix.size() == 0)
    		return;
    	if (matrix[0].size() == 0)
    		return;
    	bool row = false;
    	bool col = false; //记录行列是否自带0
    	for (int i = 0; i < matrix.size(); i++)
    	{
    		if (matrix[i][0] == 0)
    		{
    			col = true;
    			break;
    		}
    	}
    	for (int i = 0; i < matrix[0].size(); i++)
    	{
    		if (matrix[0][i] == 0)
    		{
    			row = true;
    			break;
    		}
    	}
    	for (int i = 1; i < matrix.size(); i++)
    	{
    		for (int j = 1; j < matrix[i].size(); j++)
    		{
    			if (matrix[i][j] == 0)
    			{
    				matrix[0][j] = 0;
    				matrix[i][0] = 0;
    			}
    		}
    	}
    	for (int i = 1; i < matrix.size(); i++)
    	{
    		if (matrix[i][0] == 0)
    		{
    			for (int j = 1; j < matrix[i].size(); j++)
    				matrix[i][j] = 0;
    		}
    	}
    	for (int i = 1; i < matrix[0].size(); i++)
    	{
    		if (matrix[0][i] == 0)
    		{
    			for (int j = 1; j < matrix.size(); j++)
    				matrix[j][i] = 0;
    		}
    	}
    	if (row)
    	{
    		for (int i = 0; i < matrix[0].size(); i++)
    			matrix[0][i] = 0;
    	}
    	if (col)
    	{
    		for (int i = 0; i < matrix.size(); i++)
    			matrix[i][0] = 0;
    	}
    }
};
/**int main(){
	vector<vector<int> > matrix;
	Solution s;
	s.setZeroes(matrix);
	return 0;
}
**/
