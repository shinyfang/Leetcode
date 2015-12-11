#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {//บ๖ยิด๓ะกะด
    	if (s == "")
    		return true;
    	transform(s.begin(),s.end(),s.begin(),::tolower);
    	int l = 0;
    	int r = s.length()-1;
    	while (l < r)
    	{
    		while ((l < r) && !((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9')))
    			l ++;
    		while ((l < r) && !((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9')))
    			r --;
    		if (s[l] != s[r])
    			return false;
    		l ++;
    		r --;
    	}
    	return true;
    }
};
