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