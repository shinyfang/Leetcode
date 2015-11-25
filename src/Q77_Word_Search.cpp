#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if (word == "")
    		return true;
    	for (int i = 0; i < board.size(); i++)
    	{
    		if (find(board[i].begin(),board[i].end(),word[0]) != board[i].end())
    		{
    			for (int j = 0; j < board[i].size(); j++)
    			{
    				if (board[i][j] == word[0])
    				{

    				}
    			}
    		}
    	}
    	return false;
    }
};
