#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
    	//递归会超时！！！！！！！！！！！！！！！！！！！！
    	//改了多少遍了！！！！太弱了我~~~~(>_<)~~~~
    	bool flag = false; //标记之前是否遇到过*
    	int pre1;
    	int pre2; //标记之前匹配*的s p位置
    	int p1 = 0;
    	int p2 = 0; //记录s p比较的位置
    	while (p1 < s.length())
    	{
    		if (p2 == p.length() || (s[p1] != p[p2] && p[p2] != '*' && p[p2] != '?'))
    		{
    			if (flag)
    			{
    				//为什么要用flag？因为匹配*时，可能出现当p1与*+1匹配上了，但是实际上应该与p1后面的某个仍可以匹配上且成功
    				p1 = pre1 + 1;
    				p2 = pre2 - 1;
    			}
    			else
    				return false;
    		}
    		else if (s[p1] == p[p2] || p[p2] == '?')
    		{
    			p1++;p2++;
    		}
    		else if (p[p2] == '*')
    		{
    			flag = true;
    			while (p2 < p.length() && p[p2] == '*')
    				p2++;
    			if (p2 == p.length()) //p全都是*，会完全匹配s，直接返回true
    				return true;
    			while (p1 < s.length() && s[p1] != p[p2] && p[p2] != '?')//这里记住不能和?匹配
    				p1++;
    			if (p1 == s.length()) //如果都匹配不上，直接返回false
    				return false;
    			else
    			{//返回的应该是正好匹配上的部分，不能往后移动
    				pre1 = p1;pre2 = p2;
    			}
    		}
    	}
    	while (p[p2] == '*' && p2 < p.length())
    		p2++;
    	if (p2 == p.length())
    		return true;
    	return false;
    }
};
/**int main(){
	string s = "c";
	string p = "*?*";
	Solution t;
	cout<<t.isMatch(s,p);
	return 0;
}
**/
