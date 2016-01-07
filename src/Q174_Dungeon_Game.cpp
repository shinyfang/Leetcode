#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
    	int m = dungeon.size();
    	int n = dungeon[0].size();
    	vector<vector<int> > f(m,vector<int>(n,0));
    	f[m-1][n-1] = dungeon[m-1][n-1]>0?1:1-dungeon[m-1][n-1];//就算是正数，初始也要为1
    	//初始化最后一行最后一列，只与右边或者下边有关
    	for (int i = n - 2; i >= 0; i --)
    	{
    		if (dungeon[m-1][i] >= f[m-1][i+1])
    			f[m-1][i] = 1;
    		else
    			f[m-1][i] = f[m-1][i+1] - dungeon[m-1][i];
    	}
    	for (int i = m - 2; i >= 0; i--)
    	{
    		if (dungeon[i][n-1] >= f[i+1][n-1])
    			f[i][n-1] = 1;
    		else
    			f[i][n-1] = f[i+1][n-1] - dungeon[i][n-1];
    	}
    	for (int i = m - 2; i >= 0; i--)
    	{
    		for (int j = n - 2; j >= 0; j--)
    		{
    			//找最小所需要的能量
    			f[i][j] = f[i+1][j] - dungeon[i][j] < f[i][j+1] - dungeon[i][j]?f[i+1][j] - dungeon[i][j]:f[i][j+1] - dungeon[i][j];
    			if (f[i][j] + dungeon[i][j] < 1 || f[i][j] < 1)//要考虑到dungeon本身为正数的情况
    			{
    				if (dungeon[i][j] > 0)
    					f[i][j] = 1;
    				else
    					f[i][j] = 1 - dungeon[i][j];
    			}
    		}
    	}
    	return f[0][0];
    }
};
/**int main(){
	vector<vector<int> > v;
	vector<int> a;
	a.push_back(0);
	a.push_back(-3);
	//a.push_back(0);
	v.push_back(a);
	vector<int> b;
	b.push_back(-10);
	b.push_back(0);
	//b.push_back(-1);
	v.push_back(b);
//	vector<int> c;
//	c.push_back(10);
//	c.push_back(30);
//	c.push_back(-5);
//	v.push_back(c);
	Solution s;
	cout<<s.calculateMinimumHP(v);
	return 0;
}
**/
