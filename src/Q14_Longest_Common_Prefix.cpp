#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0)//若不判断vector是否为空，则strs[0]出错
    		return "";
    	string s = strs[0];
    	cout<<s<<endl;
    	int len = 0;
    	int index = 0;
    	while(s[index]){
			for(int i=0;i<strs.size();i++){
				string temp = strs[i];
				cout<<"daibijiao:"<<temp<<endl;
				if (temp[index] == s[index]){
					cout<<"temp[index]==s[index]"<<endl;
				}
				else
					return s.substr(0,len);
			}
			len++;
			index++;
			cout<<"now_substring:"<<s.substr(0,len)<<endl;
    	}
    	return s.substr(0,len);
    }
};
int main(){
	Solution s;
	vector<string> strs;
	//strs.push_back("abcskfaf");
	//strs.push_back("abcdsotuwot");
	cout<<s.longestCommonPrefix(strs);
	return 0;
}
