#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> result;
    	if (words.size() == 0 || s.length() < words[0].length())
    		return result;
    	map<string,int> word;
    	for (int i = 0; i < words.size(); i++)
    	{
    	}
    }
};
/**int main(){
	Solution s;
	string t = "barfoothefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	s.findSubstring(t,words);
}
**/
