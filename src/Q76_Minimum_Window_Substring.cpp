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
    	int end = 0; //表示一组答案
    	string result;
    	vector<int> count1(128,0);
    	vector<int> count2(128,0);
    	for (int i = 0; i < t.length(); i++)
    		count1[t[i]] += 1;
    	int count = t.length(); //需要找到包含count长度的数
    	while (end < s.length())
    	{
    		if (count == 0)
    		{
    			while (begin <= end && (count1[s[begin]] == 0 || count2[s[begin]] > count1[s[begin]]))//更新begin，直到找到真正的头
    			{
    				if (count2[s[begin]] > count1[s[begin]])
    					count2[s[begin]] --;
    				begin ++;
    			}
    			if (count1[s[begin]] != 0)//如果找到了这个数，先判断是否存结果，再更新下一次的begin
    			{
    				//已找到所有包含t的窗
    				//cout<<"   begin="<<begin<<" end="<<end<<endl;
    				if (result == "" || end-begin+1 < result.length())//如果新的结果长度较小，则更新结果
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
    			if (count == 0)//如果end已经找到所有的t，此时end多加了一，要恢复
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
