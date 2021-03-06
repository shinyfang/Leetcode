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
