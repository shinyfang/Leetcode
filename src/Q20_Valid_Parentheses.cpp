#include<iostream>
#include<string>
#include<stack>
//好像不是最优解。。。。
using namespace std;
class Solution {
public:
    bool isValid(string s) {
    	stack<char> stk;
    	if (s.length()%2 == 1)
    		return false;
    	//stk.push(s[0]);//初始化
    	for (int i = 0; i < s.length(); i++){
    		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
    			stk.push(s[i]);
    		else{
    			if (stk.size() == 0)
    				return false;
    			else if (s[i] == ')' && stk.top() == '(')
    				stk.pop();
    			else if (s[i] == ']' && stk.top() == '[')
    				stk.pop();
    			else if (s[i] == '}' && stk.top() == '{')
    				stk.pop();
    			else
    				return false;
    		}
    	}
    	if (stk.size() == 0)
    		return true;
    	else
    		return false;
    }
};
/**int main(){
	Solution s;
	string t = "]";
	cout<<s.isValid(t);
	return 0;
}
**/
