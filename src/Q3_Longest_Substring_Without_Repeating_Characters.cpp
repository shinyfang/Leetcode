#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	bool flag[128] = {false};//标记p1 p2之间已有的字母
    	int max = 0;
    	int p1 = 0;//未重复子串头
    	int p2 = 0;//未重复子串尾
    	for(p1,p2;p1 < s.length(),p2 < s.length();){
    		if (flag[s[p2]] == false){//新来的字母没有出现过
    			flag[s[p2]] = true;
    			p2++;
    		}else{//出现过
    			int count = p2 - p1;
    			max = count>max?count:max;
    			while(s[p1] != s[p2]){
    				flag[s[p1]] = false;
    				p1++;
    			}
    			p1++;//移动完p1之后，p1 p2也要一起移动
    			p2++;
    		}
    	}
    	max = ((p2 - p1)>max)?(p2 - p1):max;
    	return max;
    }
};

/**int main(){
	string s1="dvdf";
	Solution s;
	int max = s.lengthOfLongestSubstring(s1);
	cout<<max;
	return 0;
}
**/
