#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
/**
class Solution {
public:
    string countAndSay(int n) {
    	//��ʼ��Ŀ������˼�ˣ�����������������������������������������
    	//n������ֻ�Ǽ�����1��ͷ��n������n����ʲô��ͷ�޹أ�����������������������
    	//string��append��ʱ�����appendһ��string���͵Ľ�ȥ�����������push_back�Ļ�ֻ��pushһ��char���У�������
    	string result;
    	if (n == 0)
    		return result;
    	result = "1";
    	int len = n-1;//Ҫѭ������Ĵ���
    	while (len)
    	{
    		string temp;
    		int p = 0;
    		while (p < result.length())
    		{
    			if (p < result.length()-1 && result[p]==result[p+1])
    			{
    				int x = 1;
    				while (p < result.length()-1 && result[p] == result[p+1])
    				{
    					x++;
    					p++;
    				}
    				stringstream ss1;
    				stringstream ss2;
    				string in1;
    				string in2;
    				ss1<<x;
    				ss2<<result[p];
    				in1 = ss1.str();
    				in2 = ss2.str();
    				temp.append(in1);
    				temp.append(in2);
    			}
    			else
    			{
    				temp.append("1");
    				stringstream ss;
    				string in;
    				ss<<result[p];
    				in = ss.str();//��charת��Ϊstring
    				temp.append(in);
    			}
    			p++;
    		}
    		result = temp;
    		len--;
    	}
    	return result;
    }
};
**/
class Solution {//��push_back�Ϳ���ֱ��push char���͵���~~~~
public:
    string countAndSay(int n) {
    	if (n == 0)
    		return "";
    	string result = "1";
    	int len = n-1;
    	while(len--)//Ҫѭ���Ĵ���
    	{
			string temp;
	    	int i = 0;
			while (i < result.length())
			{
				int k = i;//���Ŀǰ��ָ��index
				while (i < result.length()-1 && result[i] == result[i+1])
					i++;
				temp.push_back(i-k+'1');//Ҫpush��char���͵ģ���Ҫ+'1'
				temp.push_back(result[i]);
				i++;//ע�����ﻹ��Ҫ�ƶ�i
			}
			result = temp;
    	}
    	return result;
    }
};
/**int main(){
	int n = 3;
	Solution s;
	string result = s.countAndSay(n);
	for (int i = 0; i < result.length(); i++)
		cout<<result[i];
}
**/
