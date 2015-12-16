#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char> >& board) {
    	if (board.size() == 0 || board[0].size() == 0 || board.size() <= 2 || board[0].size() <= 2)
    		return;
    	int m = board.size();
    	int n = board[0].size();
    	for (int i = 0; i < m; i++)
    	{
    		if (board[i][0] == 'O')
    			bfs(board,i,0);
    		if (board[i][n-1] == 'O')
    			bfs(board,i,n-1);
    	}
    	for (int i = 0; i < n; i++)
    	{
    		if (board[0][i] == 'O')
    			bfs(board,0,i);
    		if (board[m-1][i] == 'O')
    			bfs(board,m-1,i);
    	}
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (board[i][j] == 'O')
    				board[i][j] = 'X';
    		}
    	}
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (board[i][j] == 'Y')
    				board[i][j] = 'O';
    		}
    	}
    }
    void bfs(vector<vector<char> >& board, int x, int y)
    {
    	vector<pair<int,int> > q;
    	q.push_back(make_pair(x,y));
    	board[x][y] = 'Y';
    	while (!q.empty())//BFS!!!!!!!!!!!!!!!!!!!!!!!!!!!
    	{
    		x = q[q.size()-1].first;
    		y = q[q.size()-1].second;
    		q.pop_back();
    		if (x > 0 && board[x-1][y] == 'O')
    		{
    			board[x-1][y] = 'Y';
    			q.push_back(make_pair(x-1,y));
    		}
    		if (y > 0 && board[x][y-1] == 'O')
    		{
    			board[x][y-1] = 'Y';
    			q.push_back(make_pair(x,y-1));
    		}
    		if (x < board.size() - 1 && board[x+1][y] =='O')
    		{
    			board[x+1][y] = 'Y';
    			q.push_back(make_pair(x+1,y));
    		}
    		if (y < board[0].size() - 1 && board[x][y+1] == 'O')
    		{
    			board[x][y+1] = 'Y';
    			q.push_back(make_pair(x,y+1));
    		}
    	}
    }
};
/**int main(){
	vector<vector<char> > board;
	vector<char> temp1;
	temp1.push_back('O');
	temp1.push_back('O');
	temp1.push_back('O');
	board.push_back(temp1);
	board.push_back(temp1);
	board.push_back(temp1);
	Solution s;
	s.solve(board);
	return 0;
}
**/
