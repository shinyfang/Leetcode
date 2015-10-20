#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.length() < (words.size())*words[0].length())
            return result;
        map<string,int> word;
        //用map存储words中的各个string，key是string，value是string出现的次数
        int len = words[0].length();
        for (int i = 0; i < words.size(); i++)
        {
            if (word.find(words[i]) == word.end())
                word[words[i]]=1;
            else
                word[words[i]]++;
        }
        int begin = 0;
        int end = s.length()-words[0].length()*words.size();
        while (begin <= end)//寻找所有string连续出现
        {
            map<string,int> temp = word;
            int p1 = begin;
            while (temp.find(s.substr(p1,len)) != temp.end() && p1 <= end)
            {
                //cout<<"find! begin:"<<s[p1]<<endl;
                string str = s.substr(p1,len);
                if (temp[str] == 1)
                    temp.erase(temp.find(str));
                else
                    temp[str]--;
                if (temp.empty())
                {
                    result.push_back(begin);
                    break;
                }
                p1 += len;
            }
            begin++;
        }
        return result;
    }
};
/**int main(){
	Solution s;
	string t = "barfoofoobarthefoobarman";
	string n1 = "bar";
	string n2 = "foo";
	string n3 = "the";
	vector<string> words;
	words.push_back(n1);
	words.push_back(n2);
	words.push_back(n3);
	vector<int>result = t.findSubstring(t,words);
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
}
**/
