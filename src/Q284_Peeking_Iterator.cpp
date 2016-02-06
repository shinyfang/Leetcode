#include<iostream>
#include<vector>
using namespace std;
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	bool hnext;//�Ƿ�ָ���Ѿ��ƶ�������һ����
	int val;//���������һ�����Ļ�����ʱ�����Ƕ���
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		hnext = false;
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!hnext)//���ָ��û�б��ƶ����ģ�ֱ�ӷ���next
		{
			val = Iterator::next();
			hnext = true;
		}
		return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (hnext)//������ƶ�����ֱ�ӷ���val�����Ұ��ƶ���־�ָ�
		{
			hnext = false;
			return val;
		}
		else
			return Iterator::next();
	}

	bool hasNext() const {
		if (hnext)
			return true;
		else
			return Iterator::hasNext();
	}
};
