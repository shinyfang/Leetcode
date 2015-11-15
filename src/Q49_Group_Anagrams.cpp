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
    	//��string�����ַ�Ϊkey��stringΪvector���͵�value��������
    	vector<vector<string> > result;
    	map<string, vector<string> > ans;
    	sort(strs.begin(),strs.end());//��������
    	for (int i = 0; i < strs.size(); i++)
    	{
    		string temp = strs[i]; //�����string�ĸ����ַ����������Ϊkey
    		sort(temp.begin(),temp.end());
    		ans[temp].push_back(strs[i]);//��ɵ��ַ���ͬ����Ϊͬһ��vector
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
