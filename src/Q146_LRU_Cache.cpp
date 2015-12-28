#include<iostream>
#include<list>
#include<map>
using namespace std;
struct Node  //list���node��ʽ������key value
{
	int key;
	int value;
	Node(int k, int v):key(k), value(v){}
};
class LRUCache{//list��˫����
public:
	list<Node> l;//list�����<key,value>����Ȼɾleast��ʱ���Ҳ���map��Ҫɾ�Ķ���
	map<int,list<Node>::iterator> m;
	int capacity; //��Ա����
    LRUCache(int capacity) {
    	this->capacity = capacity;
    }

    int get(int key) {
    	if (m.find(key) == m.end())
    		return -1;
    	l.splice(l.begin(),l,m[key]);//��key��Ӧ��Node�Ƶ�listͷȥ
    	m[key] = l.begin();//����key��ָ��
    	return m[key]->value;
    }
    void set(int key, int value) {
    	if (m.find(key) != m.end())//���key�Ѿ����ڣ����½ڵ��ֵ��˳�򼴿�
    	{
    		l.splice(l.begin(),l,m[key]);
    		m[key] = l.begin();
    		l.begin()->value = value;
    	}
    	else
    	{
    		if (l.size() == this->capacity)//���key�����ڣ�����list�Ѿ�����
    		{
    			m.erase(l.back().key);//ɾ��key
    			l.pop_back();//listҲɾ��
    		}
    		l.push_front(Node(key,value));
    		m[key] = l.begin();
    	}
    }
};
