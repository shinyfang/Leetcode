#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TrieNode {
public:
	char val;
	bool isEnd;//���������������ַ���
	vector<TrieNode*> children;
	TrieNode(){
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
	~TrieNode()
	{
		for (vector<TrieNode*>::iterator it = children.begin(); it != children.end(); it ++)
			delete *it;
	}
};
class WordDictionary {
public:
    // Adds a word into the data structure.
	WordDictionary() {
		root = new TrieNode();
	}
    void addWord(string word) {
    	if (search(word))
    		return;
    	TrieNode* p = root;
    	for (int i = 0; i < word.length(); i++)
    	{
    		TrieNode* child = p->subNode(word[i]);
    		if (child == NULL)
    		{
    			TrieNode* temp = new TrieNode(word[i]);
    			p->children.push_back(temp);
    			p = temp;
    		}
    		else
    			p = child;
    	}
    	p->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	TrieNode* p = root;
    	return search2(word,0,word.length()-1,p);
    }
    bool search2(string& word, int begin, int end, TrieNode* p)
    {
    	if (begin > end)//˵����ʱword�Ƚ�����
    		return p->isEnd;
    	if (p->children.empty())//˵����ʱwordû�Ƚ��꣬����p�Ѿ�û�ж�����
    		return false;
    	for (int i = begin; i <= end; i ++)
    	{
    		if (word[i] == '.')
    		{
    			for (vector<TrieNode*>::iterator it = p->children.begin(); it != p->children.end(); it ++)
    			{
    				if (search2(word,i+1,end,*it))
    					return true;
    			}
    			return false;
    		}
    		else
    		{
    			TrieNode* child = p->subNode(word[i]);
    			if (child == NULL)
    				return false;
    			p = child;
    		}
    	}
    	return p->isEnd;
    }
private:
    TrieNode* root;
};
/**int main(){
	WordDictionary wordDictionary;
	wordDictionary.addWord("a");
	cout<<wordDictionary.search("a.");
	return 0;
}
**/
