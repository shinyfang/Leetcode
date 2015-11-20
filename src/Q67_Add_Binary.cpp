#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		if (a == "")
			return b;
		if (b == "")
			return a;
		if (a.length() < b.length()) {
			string c = a;
			a = b;
			b = c;
		}
		int flag = 0;
		int i = a.length()-1;
		int j = b.length()-1;
		while (i >= 0 || j >= 0)
		{
			int temp1 = a[i]-'0';
			int temp2;
			if (j < 0)
				temp2 = 0;
			else
				temp2 = b[j]-'0';
			int sum = temp1 + temp2 + flag;
			if (sum >= 2)
			{
				a[i] = (sum%2) + '0';
				flag = 1;
			}
			else
			{
				a[i] = sum + '0';
				flag = 0;
			}
			i--;j--;
		}
		if (flag == 1)
			a.insert(a.begin(),'1');
		return a;
	}
};
/**int main() {
	string a = "1111";
	string b = "1111";
	Solution s;
	string result = s.addBinary(a, b);
	for (int i = 0; i < result.length(); i++)
		cout << result[i];
	return 0;
}
**/
