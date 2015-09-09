#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1)
        	return s;
        int max = 1;//默认最长的长度是1
        int m1 = 0;//m1 m2指向最长回文的前后index
        int m2 = 0;
        for(int i=0;i<s.length();i++){
        	int count = 1;
        	int p1 = i - 1;
        	int p2 = i + 1;
        	while(p1>=0 && p2<s.length() && s[p1]==s[p2]){//分为奇偶讨论
        		count+=2;
        		p1--;
        		p2++;
        	}
        	if(count>max){
        		max = count;
        		m1 = p1+1;
        		m2 = p2-1;
        	}
        	if (s[i]==s[i+1])
        	{
        		count = 2;
        		p1 = i-1;
        		p2 = i+2;
        		while(p1>=0 && p2<s.length() && s[p1]==s[p2]){
        			count+=2;
        		    p1--;
        		    p2++;
        		}
        	}
        	if(count>max){
        	    max = count;
        	    m1 = p1+1;
        	    m2 = p2-1;
        	}
        }
        return s.substr(m1,m2-m1+1);//注意substr的用法，返回子串，m1表示子串的头index，第二个参数返回子串的长度
    }
};
/**int main(){
	string s="ccc";
	Solution t;
	cout<<t.longestPalindrome(s);
	return 0;
}
**/
