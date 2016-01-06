#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
        	return to_string(numerator,denominator);
        string result;
        if (numerator < 0 ^ denominator < 0)
        	result += "-";
        long long int n = abs(numerator);
        long long int d = abs(denominator);
        result += to_string(n,d);
        n = n%d;
        if (n == 0)
        	return result;
        else
        	result += ".";
        map<int, int> m;  //key存余数，value存余数在result中的位置，便于遇到重复的余数将(插入进去
        while (n)
        {
        	if (m.find(n) != m.end())
        	{
        		result.insert(m[n],"(");
        		result += ")";
        		break;
        	}
        	m[n] = result.size();
        	n = 10*n;
        	result += to_string(n,d);
        	n = n%d;
        }
        return result;
    }
    string to_string(long long int n, long long int d)
    {
    	string result;
    	long long int r = n/d;
    	stringstream ss;
    	ss<<r;
    	ss>>result;
    	return result;
    }
};
/**int main(){
	int numerator = -1;
	int denominator = -2147483648;
	Solution s;
	string r = s.fractionToDecimal(numerator,denominator);
	for (int i = 0; i < r.length(); i++)
		cout<<r[i];
	return 0;
}
**/
