#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
	char val;
	bool isEnd;
	vector<TrieNode*> children;//�ص�����Ҫ��ס����ڵ�Ķ��ӣ�Ҳ��������ַ�����������ĸ
    TrieNode() {//���캯��
    	val = ' ';
    	isEnd = false;
    }
    TrieNode(char ch) {
    	val = ch;
    	isEnd = false;
    }
    TrieNode* subNode(char ch) {//�����Ƿ���root�Ķ��ӣ�������
    	for (vector<TrieNode*>::iterator it = children.begin(); it != children.end(); it ++)
    	{
    		if ((*it)->val == ch)
    			return *it;//����Ҳ��һ��TrieNode�ṹ
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
    		TrieNode* child = p->subNode(word[i]);//������û�������ĸ
    		if (child == NULL)//���û�о�Ҫ�½�
    		{
    			TrieNode* temp = new TrieNode(word[i]);
    			p->children.push_back(temp);
    			p = temp;//�½��������ĸ��Ҫ�������ĸ֮��ʼ����ʣ�µ���ĸ
    		}
    		else
    			p = child;//����������ĸ��ֱ�Ӹ��������ĸ֮�����
    	}
    	p->isEnd = true;//������ַ�����β���
    }

    // Returns if the word is in the trie.
    bool search(string word) {//Ҫ�ж��Ƿ���һ���ַ���������Ҫ�жϽ�β�ǲ���end
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
    	//��Ҫ������words��ϳ�trie��ʽ������������ʱ�����ʹ�ü�֦����
    	if (words.size() == 0 || board.size() == 0 || board[0].size() == 0)
    		return r;
    	Trie trie;//��Ķ���
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
    //board�д��Ƚϵĺ������꣬�Ѿ��Ƚϳɹ����ַ���res���Ƿ��ù��ı��f
    {
    	//ÿ�ΰ�Ҫ�Ƚϵ��ַ�����res�У�������trie���Ƿ���res��ͷ���ַ���
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
