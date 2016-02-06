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
	bool hnext;//是否指针已经移动到了下一个数
	int val;//如果存在下一个数的话，此时的数是多少
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		hnext = false;
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!hnext)//如果指针没有被移动过的，直接返回next
		{
			val = Iterator::next();
			hnext = true;
		}
		return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (hnext)//如果被移动过，直接返回val，并且把移动标志恢复
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
