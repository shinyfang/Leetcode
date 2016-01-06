#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2)
        	return 0;
        int p1 = 0;
        int p2 = 0;
        while (p1 < version1.length() || p2 < version2.length())
        {
        	int i = 0;
        	for (int k = p1; k < version1.length(); k++)
        	{
        		if (version1[k] == '.')
        			break;
        		i ++;
        	}
        	string a = version1.substr(p1,i);
        	p1 += i + (version1[p1+i]=='.'?1:0);
        	int j = 0;
        	for (int k = p2; k < version2.length(); k++)
        	{
        		if (version2[k] == '.')
        			break;
        		j ++;
        	}
        	string b = version2.substr(p2,j);
        	p2 += j + (version2[p2+j]?1:0);
        	int m = 0;
        	for (int k = 0; k < a.length(); k++)
        		m = m*10 + (a[k] - '0');
        	int n = 0;
        	for (int k = 0; k < b.length(); k++)
        		n = n*10 + (b[k] - '0');
        	if (m > n)
        		return 1;
        	else if (m < n)
        		return -1;
        }
        if (p1 != version1.length() && p2 == version2.length())
        	return 1;
        if (p1 == version1.length() && p2 != version2.length())
        	return -1;
        return 0;
    }
};
