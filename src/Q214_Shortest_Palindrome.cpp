#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
    	//s与它的逆t之间的比较，t的尾部和s的头部重合的部分，不考虑
    	if (s.length() < 2)
    		return s;
    	string t(s.rbegin(),s.rend());
    	int r = s.length() - 1;
    	int i = s.length() - 2;
    	while (i >= 0)
    	{
    		if (t.substr(i,s.length()-i) == s.substr(0,s.length()-i))
    			r = i < r ? i : r;
    		i --;
    	}
    	s = t.substr(0,r) + s;
    	return s;
    }
};
/**int main(){
	string s = "abcd";
	Solution so;
	string r = so.shortestPalindrome(s);
	for (int i = 0; i < r.length(); i ++)
		cout<<r[i];
	return 0;
}
**/
