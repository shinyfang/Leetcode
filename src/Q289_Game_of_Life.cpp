#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	 * 0 die-die
	 * 1 live-live
	 * 2 live-die
	 * 3 die-live
	 *
	 *
	 * <2 live-die
	 * =2||3 live-live
	 * >3 live-die
	 * =3 die-live
	 */
	void gameOfLife(vector<vector<int> >& board) {
		if (board.size() == 0 || board[0].size() == 0)
			return;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				int live = 0;
				for (int x = i - 1; x <= i + 1; x++)
				{
					for (int y = j - 1; y <= j + 1; y++)
					{
						if (x < 0 || x >= board.size() || y < 0
								|| y >= board[0].size())
							continue;
						if (board[x][y] == 1 || board[x][y] == 2)
							live++;
					}
				}
				if (board[i][j] == 1 && (live < 3 || live > 4))
					board[i][j] = 2;
				else if (board[i][j] == 0 && live == 3)
					board[i][j] = 3;
			}
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++)
				board[i][j] %= 2;
		}
	}
};
