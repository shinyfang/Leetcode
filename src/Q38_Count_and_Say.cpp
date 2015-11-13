#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
/**
class Solution {
public:
    string countAndSay(int n) {
    	//开始题目理解错意思了！！！！！！！！！！！！！！！！！！！！！
    	//n是意义只是计算以1开头第n个数，n与以什么开头无关！！！！！！！！！！！！
    	//string用append的时候必须append一个string类型的进去，但是如果用push_back的话只用push一个char就行！！！！
    	string result;
    	if (n == 0)
    		return result;
    	result = "1";
    	int len = n-1;//要循环计算的次数
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
    				in = ss.str();//将char转换为string
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
class Solution {//用push_back就可以直接push char类型的啦~~~~
public:
    string countAndSay(int n) {
    	if (n == 0)
    		return "";
    	string result = "1";
    	int len = n-1;
    	while(len--)//要循环的次数
    	{
			string temp;
	    	int i = 0;
			while (i < result.length())
			{
				int k = i;//标记目前所指的index
				while (i < result.length()-1 && result[i] == result[i+1])
					i++;
				temp.push_back(i-k+'1');//要push进char类型的，需要+'1'
				temp.push_back(result[i]);
				i++;//注意这里还需要移动i
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
