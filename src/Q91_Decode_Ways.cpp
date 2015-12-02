#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
    	if (s == "" || s[0] == '0')
    		return 0;
    	if (s == "")
    		return 0;
    	if (s.length() == 1)
    		return 1;
    	int f0 = 1;
    	int f1 = 1;
    	int p = 1;
    	while (p < s.length())
    	{
    		if (s[p] == '0' && (s[p-1] == '0' || s[p-1]-'0' > 2)) //考虑 100 或者30这种情况
    			return 0;
    		if ((s[p-1] == '1' || (s[p-1] == '2' && s[p]-'0' <= 6)) && s[p] != '0') //可以跳一步，可以跳两步
    		{
    			int temp = f0 + f1;
    			f0 = f1;
    			f1 = temp;
    		}
    		else if (s[p-1]-'0' <= 2 && s[p] == '0') //5101 5201这样只能从5跳过来
    		{
    			int temp = f0;
    			f0 = f1;
    			f1 = temp;
    		}
    		else //其他情况是 连续两个>26
    			f0 = f1;
    		p++;
    	}
    	return f1;
    }
};
/**int main(){
	string t = "10";
	Solution s;
	cout<<s.numDecodings(t);
	return 0;
}
**/
