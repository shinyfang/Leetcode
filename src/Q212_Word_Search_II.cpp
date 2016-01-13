#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
	char val;
	bool isEnd;
	vector<TrieNode*> children;//重点在于要记住这个节点的儿子，也就是这个字符串的余下字母
    TrieNode() {//构造函数
    	val = ' ';
    	isEnd = false;
    }
    TrieNode(char ch) {
    	val = ch;
    	isEnd = false;
    }
    TrieNode* subNode(char ch) {//查找是否是root的儿子，并返回
    	for (vector<TrieNode*>::iterator it = children.begin(); it != children.end(); it ++)
    	{
    		if ((*it)->val == ch)
    			return *it;//儿子也是一个TrieNode结构
    	}
    	return NULL;
    }
    ~TrieNode() {
    	for (vector<TrieNode*>::iterator it = children.begin(); it != children.end(); it ++)
    		delete *it;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
    	if (search(word))
    		return;
    	TrieNode* p = root;
    	for (int i = 0; i < word.length(); i ++)
    	{
    		TrieNode* child = p->subNode(word[i]);//先找有没有这个字母
    		if (child == NULL)//如果没有就要新建
    		{
    			TrieNode* temp = new TrieNode(word[i]);
    			p->children.push_back(temp);
    			p = temp;//新建了这个字母，要从这个字母之后开始插入剩下的字母
    		}
    		else
    			p = child;//如果有这个字母，直接跟着这个字母之后插入
    	}
    	p->isEnd = true;//把这个字符串结尾标记
    }

    // Returns if the word is in the trie.
    bool search(string word) {//要判断是否是一个字符串，所以要判断结尾是不是end
    	TrieNode* p = root;
    	for (int i = 0; i < word.length(); i++)
    	{
    		p = p->subNode(word[i]);
    		if (p == NULL)
    			return false;
    	}
    	return p->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
    	TrieNode* p = root;
    	for (int i = 0; i < prefix.length(); i ++)
    	{
    		TrieNode* child = p->subNode(prefix[i]);
    		if (child == NULL)
    			return false;
    		p = child;
    	}
    	return true;
    }
    ~Trie()
    {
    	delete root;
    }
private:
    TrieNode* root;
};

class Solution {
public:
	vector<string> r;
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    	//把要搜索的words组合成trie形式，这样搜索的时候可以使得剪枝更快
    	if (words.size() == 0 || board.size() == 0 || board[0].size() == 0)
    		return r;
    	Trie trie;//类的对象
    	for (int i = 0; i < words.size(); i ++)
    		trie.insert(words[i]);
    	vector<vector<bool> > f(board.size(), vector<bool>(board[0].size(),false));
    	for (int i = 0; i < board.size(); i ++)
    	{
    		for (int j = 0; j < board[0].size(); j ++)
    			dfs(board,i,j,"",trie,f);
    	}
    	return r;
    }
    void dfs(vector<vector<char> >& board, int x, int y, string res, Trie& trie, vector<vector<bool> > f)
    //board中待比较的横纵坐标，已经比较成功的字符串res，是否用过的标记f
    {
    	//每次把要比较的字符加入res中，查找在trie中是否有res开头的字符串
    	if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
    		return;
    	if (f[x][y])
    		return;
    	res += board[x][y];
    	if (!trie.startsWith(res))
    		return;
    	if (trie.search(res))
    		r.push_back(res);
    	f[x][y] = true;
    	dfs(board,x-1,y,res,trie,f);
    	dfs(board,x+1,y,res,trie,f);
    	dfs(board,x,y-1,res,trie,f);
    	dfs(board,x,y+1,res,trie,f);
    	f[x][y] = false;
    }
};
