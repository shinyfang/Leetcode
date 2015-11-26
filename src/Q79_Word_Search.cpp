#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
    	if (word == "")
    		return true;
    	vector<vector<bool> > used(board.size(),vector<bool>(board[0].size(),false));
    	for (int i = 0; i < board.size(); i++)
    	{
    		for (int j = 0; j < board[0].size(); j++)
    		{
    			if (dfs(board,word,used,0,i,j))
    				return true;
    		}
    	}
    	return false;
    }
    bool dfs(vector<vector<char> >& board, string word, vector<vector<bool> > &used, int index, int i, int j)
    {
    	if (index == word.length())
    		return true;
    	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
    		return false;
    	if (used[i][j])
    		return false;
    	if (board[i][j] != word[index])
    		return false;
    	//找到了相同的数
    	used[i][j] = true;
    	bool result = dfs(board,word,used,index+1,i-1,j) || dfs(board,word,used,index+1,i+1,j) || dfs(board,word,used,index+1,i,j-1) || dfs(board,word,used,index+1,i,j+1);
    	used[i][j] = false; //DFS的精髓？？？
    	return result;
    }
};
