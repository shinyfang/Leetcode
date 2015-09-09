#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1)
        	return s;
        int max = 1;//Ĭ����ĳ�����1
        int m1 = 0;//m1 m2ָ������ĵ�ǰ��index
        int m2 = 0;
        for(int i=0;i<s.length();i++){
        	int count = 1;
        	int p1 = i - 1;
        	int p2 = i + 1;
        	while(p1>=0 && p2<s.length() && s[p1]==s[p2]){//��Ϊ��ż����
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
        return s.substr(m1,m2-m1+1);//ע��substr���÷��������Ӵ���m1��ʾ�Ӵ���ͷindex���ڶ������������Ӵ��ĳ���
    }
};
/**int main(){
	string s="ccc";
	Solution t;
	cout<<t.longestPalindrome(s);
	return 0;
}
**/
