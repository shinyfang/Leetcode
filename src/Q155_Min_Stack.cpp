#include<iostream>
#include<vector>
using namespace std;
class MinStack {
public:
	vector<int> stk;
	vector<int> min;
    void push(int x) {
    	stk.push_back(x);
    	if (min.empty() || min[min.size()-1] > x)
    		min.push_back(x);
    	else
    		min.push_back(min[min.size()-1]);
    }
    void pop() {
    	stk.pop_back();
    	min.pop_back();
    }
    int top() {
    	return stk[stk.size()-1];
    }
    int getMin() {
    	return min[min.size()-1];
    }
};
