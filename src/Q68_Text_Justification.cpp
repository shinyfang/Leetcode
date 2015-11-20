#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> result;
    	int len = result[0].length(); //占据多少长度
    	int start = 0;//从第start开始计数
    	int num = 1; //已经存了几个数
    	for (int i = 0; i < words.size(); i++)
    	{
    		if (len+1+words[i].length() > maxWidth)
    		{
    			int length = len - (num-1);
    			int gap;
    			if ((maxWidth-length)%(num-1) == 0)
    			{
    				gap = (maxWidth-length)/(num-1);
    				string temp;
    				string gapgap(gap,' ');
    				for (int j = start; j < i; j++)
    				{
    					if (j == start)
    						temp.append(words[j]);
    					else
    						temp.append(gapgap+words[j]);
    				}
    				start = i;
    				num = 1;
    				len = words[i].length();
    				continue;
    			}
    			else
    			{
    				gap = (maxWidth-length)/(num-1);
    				int over = maxWidth-gap*(num-1);
    				int re = (num-1);
    				while (over != 0)
    				{

    				}
    			}
    		}
    		else
    		{
    			len += (words[i].length()+1);
    			num++;
    		}
    	}
    }
};
/**int main(){
	vector<string> words;
	int maxWidth;
	Solution s;
	vector<string> result = s.fullJustify(words,maxWidth);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].length(); j++)
			cout<<result[i][j];
		cout<<endl;
	}
	return 0;
}
**/
