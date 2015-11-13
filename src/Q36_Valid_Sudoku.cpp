#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char > >& board) {
    	//board的vector中存了9行，每行存了9个数
    	//判断每行是否满足
    	int a[9];
    	int b[9];//a行，b列
    	for (int i = 0; i < 9; i++)//行列可以同时遍历
    	{
    		memset(a,0,sizeof(int)*9);
    		memset(b,0,sizeof(int)*9);
    		for (int j = 0; j < 9; j++)
    		{
    			if (board[i][j] != '.')
    			{
    				if (a[board[i][j]-'1'] == 0)//board里的char！！！
						a[board[i][j]-'1'] = 1;
					else
						return false;
    			}
    			if (board[j][i] != '.')
    			{
    				if (b[board[j][i]-'1'] == 0)
						b[board[j][i]-'1'] = 1;
					else
						return false;
    			}
    		}
    	}
    	for (int i = 0; i < 9; i += 3)//九个格子分开遍历
    	{
    		for (int j = 0; j < 9; j += 3)
    		{
    			memset(a,0,sizeof(int)*9);
    			int temp1 = i;
    			int k1 = 3;
    			while(k1--)
    			{
    				int temp2 = j;
    				int k2 = 3;
    				while(k2--)
    				{
    					if (board[temp1][temp2] != '.')
    					{
    						if (a[board[temp1][temp2]-'1'] == 0)
								a[board[temp1][temp2]-'1'] = 1;
							else
								return false;
    					}
						temp2++;
    				}
    				temp1++;
    			}
    		}
    	}
    	return true;
    }
};
/**int main(){
	vector<vector<char> > board;
	Solution s;
	cout<<s.isValidSudoku(board);
	return 0;
}
**/
