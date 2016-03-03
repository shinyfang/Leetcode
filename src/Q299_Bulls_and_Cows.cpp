#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
    	map<char,int> m;
    	for (int i = 0; i < secret.length(); i ++)
    		m[secret[i]] ++;
    	int A = 0;
    	int B = 0;
    	for (int i = 0; i < guess.length(); i ++)
    	{
    		if (m.find(guess[i]) != m.end() && m[guess[i]] != 0)
    		{
    			B ++;
    			m[guess[i]] --;
    		}
    		if (guess[i] == secret[i])
    			A ++;
    	}
    	string a = int2str(A);
    	string b = int2str(B-A);
    	return (a+"A"+b+"B");
    }
    string int2str(int x)
    {
    	stringstream ss;
    	ss<<x;
    	string r;
    	ss>>r;
    	return r;
    }
};
