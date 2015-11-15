#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
    	//以string各个字符为key，string为vector类型的value，存起来
    	vector<vector<string> > result;
    	map<string, vector<string> > ans;
    	sort(strs.begin(),strs.end());//整体排序
    	for (int i = 0; i < strs.size(); i++)
    	{
    		string temp = strs[i]; //以组成string的各个字符排序后的组合为key
    		sort(temp.begin(),temp.end());
    		ans[temp].push_back(strs[i]);//组成的字符相同，归为同一个vector
    	}
    	for (map<string, vector<string> >::iterator it = ans.begin(); it != ans.end(); it++)
    	{
    		result.push_back(it->second);
    	}
    	return result;
    }
};
/**int main(){
	vector<string> strs;
	Solution s;
	s.groupAnagrams(strs);
	return 0;
}
**/
