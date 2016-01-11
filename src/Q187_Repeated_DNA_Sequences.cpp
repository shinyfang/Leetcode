#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> result;
    	map<int,int> m;
    	if (s.length() <= 10)
    		return result;
    	for (int i = 0; i < s.length(); i++)
    	{
    		if (i + 9 >= s.length())
    			break;
    		int key = 0;
    		int count = 10;
    		int j = i;
    		while (count)
    		{
    			int temp;
    			if (s[j] == 'A')
    				temp = 0;
    			else if (s[j] == 'C')
    				temp = 1;
    			else if (s[j] == 'G')
    				temp = 2;
    			else if (s[j] == 'T')
    				temp = 3;
    			key = key << 2 | temp;//二进制表示ACGT，int表示10个字符串
    			j ++;
    			count --;
    		}
    		if (m.find(key) != m.end())
    		{
    			if (m[key] == 1)
    			{
    				string temp = s.substr(i,10);
    				result.push_back(temp);
    			}
    			m[key] ++;
    		}
    		else
    			m[key] = 1;
    	}
    	return result;
    }
};
/**int main(){
	string s = "AAAAAAAAAAA";
	Solution so;
	vector<string> r = so.findRepeatedDnaSequences(s);
	for (int i = 0; i < r.size(); i++)
	{
		for (int j = 0; j < r[i].length(); j++)
			cout<<r[i][j];
		cout<<endl;
	}
	return 0;
}
**/
