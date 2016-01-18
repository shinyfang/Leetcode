#include<iostream>
#include<queue>
using namespace std;
class Stack {
public:
	queue<int> q1;
	queue<int> q2;
    // Push element x onto stack.
    void push(int x) {
    	if (q1.empty())
    	{
    		q1.push(x);
    		while (!q2.empty())
    		{
    			q1.push(q2.front());
    			q2.pop();
    		}
    	}
    	else
    	{
    		q2.push(x);
    		while (!q1.empty())
    		{
    			q2.push(q1.front());
    			q1.pop();
    		}
    	}
    }
    // Removes the element on top of the stack.
    void pop() {
    	if (q1.empty())
    		q2.pop();
    	else
    		q1.pop();
    }
    // Get the top element.
    int top() {
    	if (q1.empty())
    		return q2.front();
    	else
    		return q1.front();
    }
    // Return whether the stack is empty.
    bool empty() {
    	if (q1.empty() && q2.empty())
    		return true;
    	return false;
    }
};
