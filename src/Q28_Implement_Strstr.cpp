#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
        	return 0;
        if (haystack == "" || haystack.length() < needle.length())
        	return -1;
        int index = -1;//³õÊ¼»¯
        for (int i = 0; i < haystack.length(); i++)
        {
        	if (haystack[i] == needle[0])
        	{
        		cout<<"==needle[0] "<<i<<endl;
        		if (haystack.length() - i < needle.length())
        			return -1;
        		else
        		{
        			int temp = i;
        			for (int j = 0; j < needle.length(); temp++, j++)
        			{
        				if (haystack[temp] != needle[j])
        					break;
        				cout<<haystack[temp]<<"=="<<needle[j]<<endl;
        			}
        			if (temp == i+needle.length())
        				return i;
        			else
        				continue;
        		}
        	}
        }
        return index;
    }
};
/**int main(){
	Solution s;
	string haystack = "mississippi";
	string needle = "issip";
	cout<<s.strStr(haystack,needle);
	return 0;
}
**/
