#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
    	if (word1 == "")
    		return word2.length();
    	if (word2 == "")
    		return word1.length();
    	int m = word1.length();
    	int n = word2.length();
    	int **result;
    	result = new int*[m+1];
    	for (int i = 0; i < m+1; i++) //这个动态二位数组是m+1 * n+1的，与普通二位数组不一样
    		result[i] = new int[n+1];
    	for (int i = 0; i < m+1; i++)
    	{
    		result[i][0] = i;
    	}
    	for (int j = 0; j < n+1; j++)
    	{
   			result[0][j] = j;
    	}
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (word1[i] == word2[j])
    				result[i+1][j+1] = result[i][j];
    			else
    			{
    				int temp = result[i][j]<result[i+1][j]?result[i][j]:result[i+1][j];
    				temp = result[i][j+1]<temp?result[i][j+1]:temp;
    				result[i+1][j+1] = temp + 1;
    			}
    		}
    	}
    	return result[m][n];
    }
};
/**int main(){
	string word1 = "aa";
	string word2 = "bbaa";
	Solution s;
	cout<<s.minDistance(word1,word2);
	return 0;
}
**/
