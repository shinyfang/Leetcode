#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
    	int r = 0;
    	if (grid.size() == 0 || grid[0].size() == 0)
    		return r;
    	for (int i = 0; i < grid.size(); i++)
    	{
    		for (int j = 0; j < grid[i].size(); j++)
    		{
    			if (grid[i][j] != '1')//每次遇到单独一块1的地方，都会改成2标记，下次就不会再计算这块地方
    				continue;
    			r ++;
    			numI(grid,i,j);
    		}
    	}
    	return r;
    }
    void numI(vector<vector<char> >& grid, int x, int y)
    {
    	if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
    		return;
    	if (grid[x][y] == '1')//只有当找到1时，才把所有的1置为2
    	{
    		grid[x][y] = '2';
			numI(grid,x-1,y);
			numI(grid,x+1,y);
			numI(grid,x,y-1);
			numI(grid,x,y+1);
    	}
    }
};
/**int main()
{
	vector<vector<char> > grid;
	vector<char> temp;
	temp.push_back('1');
	temp.push_back('0');
	grid.push_back(temp);
	Solution s;
	cout<<s.numIslands(grid);
	return 0;
}
**/
