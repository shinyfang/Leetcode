#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
    	if (s == "")
    		return 0;
    	int i = s.length()-1;
    	while (i > 0 && s[i] == ' ')
    		i--;
    	if (s[i] == ' ')
    		return 0;
    	int result = 0;
    	for (int j = i; j >= 0; j--)
    	{
    		if (s[j] == ' ')
    			return result;
    		else
    			result++;
    	}
    	return result;
    }
};
/**int main()
{
	string s = "h";
	Solution t;
	cout<<t.lengthOfLastWord(s);
	return 0;
}
**/
