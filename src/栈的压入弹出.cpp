#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> push, vector<int> pop)
	{
		bool result = false;
		if (push.size() != pop.size())
			return result;
		int p1 = 0;
		int p2 = 0;
		stack<int> stk;
		while (p1 != push.size() || p2 != pop.size())
		{
			while (stk.empty() || stk.top() != pop[p2])
			{
				if (p1 == push.size())
					break;
				stk.push(push[p1]);
				p1++;
			}
			if (stk.top() != pop[p2])
				break;
			stk.pop();
			p2 ++;
		}
		if (stk.empty() && p2 == pop.size())
			result = true;
		return result;
	}
};
/**int main(){
	vector<int> push;
	push.push_back(1);
	push.push_back(2);
	push.push_back(3);
	push.push_back(4);
	push.push_back(5);
	vector<int> pop;
	pop.push_back(4);
	pop.push_back(5);
	pop.push_back(3);
	pop.push_back(1);
	pop.push_back(2);
	Solution s;
	cout<<s.IsPopOrder(push,pop);
	return 0;
}
**/
