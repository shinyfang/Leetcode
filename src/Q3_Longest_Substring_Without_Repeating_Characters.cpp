#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	bool flag[128] = {false};//���p1 p2֮�����е���ĸ
    	int max = 0;
    	int p1 = 0;//δ�ظ��Ӵ�ͷ
    	int p2 = 0;//δ�ظ��Ӵ�β
    	for(p1,p2;p1 < s.length(),p2 < s.length();){
    		if (flag[s[p2]] == false){//��������ĸû�г��ֹ�
    			flag[s[p2]] = true;
    			p2++;
    		}else{//���ֹ�
    			int count = p2 - p1;
    			max = count>max?count:max;
    			while(s[p1] != s[p2]){
    				flag[s[p1]] = false;
    				p1++;
    			}
    			p1++;//�ƶ���p1֮��p1 p2ҲҪһ���ƶ�
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
