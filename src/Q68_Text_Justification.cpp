#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> result;
    	int begin = 0;
    	int len = 0;
    	int i = 0;
    	while (i < words.size())
    	{
    		len = (i == begin?(len+words[i].length()):(len+1+words[i].length()));;
    		if (len > maxWidth)
    		{
    			len -= (1+words[i].length());
    			int gap = (i-begin-1 > 0)?(maxWidth-len)/(i-begin-1):0;
    			int overgap = (i-begin-1 > 0)?(maxWidth-len)%(i-begin-1):(maxWidth-len);
    			string temp;
    			for (int j = begin; j < i; j++)
    			{
    				if (j == begin)
    					temp = words[j];
    				else
    				{
    					temp += ' ';
    					for (int k = 0; k < gap; k++)
    						temp += ' ';
    					if (overgap > 0)
    					{
    						temp += ' ';
    						overgap--;
    					}
    					temp += words[j];
    				}
    			}
    			//考虑这行只有一个数，则进入不了上面的else循环
    			for (int k = 0; k < overgap; k++)
    				temp += ' ';
    			result.push_back(temp);
    			len = 0;
    			begin = i;
    		}
    		else
    		{
    			if (i != words.size()-1)
    				i++;
    			else
    			{
    				string temp;
    				//如果到最后一个数都没有超过L，则为最后一行
    				for (int j = begin; j <= i; j++)
    				{
    					if (j == begin)
    						temp = words[j];
    					else
    					{
    						temp += ' ';
    						temp += words[j];
    					}
    				}
    				for (int k = 0; k < maxWidth-len; k++)
    				    temp += ' ';
    				result.push_back(temp);
    				break;
    			}
    		}
    	}
    	return result;
    }
};
/**int main(){
	vector<string> words;
	//string temp = "";
	words.push_back("What");
	words.push_back("must");
	words.push_back("be");
	words.push_back("shall");
	words.push_back("be.");
	//words.push_back("text");
	//words.push_back("justification");
	int maxWidth = 12;
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
