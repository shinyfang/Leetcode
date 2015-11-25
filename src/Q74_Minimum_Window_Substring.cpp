#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
    	if (s == "" || t == "")
    		return "";
    	int begin = 0;
    	int end = 0; //��ʾһ���
    	string result;
    	vector<int> count1(128,0);
    	vector<int> count2(128,0);
    	for (int i = 0; i < t.length(); i++)
    		count1[t[i]] += 1;
    	int count = t.length(); //��Ҫ�ҵ�����count���ȵ���
    	while (end < s.length())
    	{
    		if (count == 0)
    		{
    			while (begin <= end && (count1[s[begin]] == 0 || count2[s[begin]] > count1[s[begin]]))//����begin��ֱ���ҵ�������ͷ
    			{
    				if (count2[s[begin]] > count1[s[begin]])
    					count2[s[begin]] --;
    				begin ++;
    			}
    			if (count1[s[begin]] != 0)//����ҵ�������������ж��Ƿ�������ٸ�����һ�ε�begin
    			{
    				//���ҵ����а���t�Ĵ�
    				//cout<<"   begin="<<begin<<" end="<<end<<endl;
    				if (result == "" || end-begin+1 < result.length())//����µĽ�����Ƚ�С������½��
    				{
    					result = "";
    					for (int i = begin; i <= end; i++)
    						result += s[i];
    				}
    				count2[s[begin]] --;
    				count ++;
    				begin ++;
    				end ++;
    			}
    			if (begin >= s.length())
    				break;
    		}
    		else
    		{
    			while (end < s.length() && count != 0)
    			{
    				if (count1[s[end]] != 0)
    				{
    					count2[s[end]] ++;
    					if (count2[s[end]] <= count1[s[end]])
    						count --;
    				}
    				end ++;
    			}
    			if (count == 0)//���end�Ѿ��ҵ����е�t����ʱend�����һ��Ҫ�ָ�
    				end --;
    			//cout<<"begin="<<begin<<" end="<<end<<endl;
    			//cout<<count2['A']<<" "<<count2['B']<<" "<<count2['C']<<endl;
    		}
    	}
    	return result;
    }
};
/**int main(){
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution o;
	string result = o.minWindow(s,t);
	for (int i = 0; i < result.length(); i++)
		cout<<result[i];
	return 0;
}
**/
