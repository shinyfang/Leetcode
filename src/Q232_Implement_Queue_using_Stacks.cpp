#include<iostream>
#include<stack>
using namespace std;
class Queue {
public:
	stack<int> stk1;
	stack<int> stk2;
    // Push element x to the back of queue.
    void push(int x) {
    	if (stk1.empty())
    	{
    		while (!stk2.empty())
    		{
    			stk1.push(stk2.top());
    			stk2.pop();
    		}
    		stk2.push(x);
    		while (!stk1.empty())
    		{
    			stk2.push(stk1.top());
    			stk1.pop();
    		}
    	}
    	else
    	{
    		while (!stk1.empty())
    		{
    			stk2.push(stk1.top());
    			stk1.pop();
    		}
    		stk1.push(x);
    		while (!stk2.empty())
    		{
    			stk1.push(stk2.top());
    			stk2.pop();
    		}
    	}
    }

    // Removes the element from in front of queue.
    void pop(void) {
    	if (stk1.empty())
    		stk2.pop();
    	else
    		stk1.pop();
    }

    // Get the front element.
    int peek(void) {
    	if (stk1.empty())
    		return stk2.top();
    	else
    		return stk1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
    	return (stk1.empty() && stk2.empty());
    }
};
