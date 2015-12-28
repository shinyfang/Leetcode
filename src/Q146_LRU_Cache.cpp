#include<iostream>
#include<list>
#include<map>
using namespace std;
struct Node  //list存成node形式，包含key value
{
	int key;
	int value;
	Node(int k, int v):key(k), value(v){}
};
class LRUCache{//list是双链表
public:
	list<Node> l;//list必须存<key,value>，不然删least的时候找不到map中要删的东西
	map<int,list<Node>::iterator> m;
	int capacity; //成员变量
    LRUCache(int capacity) {
    	this->capacity = capacity;
    }

    int get(int key) {
    	if (m.find(key) == m.end())
    		return -1;
    	l.splice(l.begin(),l,m[key]);//把key对应的Node移到list头去
    	m[key] = l.begin();//更新key的指针
    	return m[key]->value;
    }
    void set(int key, int value) {
    	if (m.find(key) != m.end())//如果key已经存在，更新节点的值和顺序即可
    	{
    		l.splice(l.begin(),l,m[key]);
    		m[key] = l.begin();
    		l.begin()->value = value;
    	}
    	else
    	{
    		if (l.size() == this->capacity)//如果key不存在，但是list已经满了
    		{
    			m.erase(l.back().key);//删除key
    			l.pop_back();//list也删除
    		}
    		l.push_front(Node(key,value));
    		m[key] = l.begin();
    	}
    }
};
