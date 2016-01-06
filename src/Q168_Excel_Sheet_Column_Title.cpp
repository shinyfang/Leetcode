#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
    	string result = "";
    	while (n)
    	{
    		result = char((n - 1) % 26 + 'A') + result;
    		n = (n - 1) / 26;
    	}
    	return result;
    }
};
/*int main(){
	int n = 27;
	Solution s;
	string r = s.convertToTitle(n);
	for (int i = 0; i < r.length(); i++)
		cout<<r[i];
	return 0;
}
**/
