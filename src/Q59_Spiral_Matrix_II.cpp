#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
	//4ms，居然很慢！！！！！！！！！有待改进呀！！！！！！！
    vector<vector<int> > generateMatrix(int n) {
    	//先存成矩阵，再转变成vector
    	vector<vector<int> > result;
    	if (n == 0)
    		return result;
    	n = abs(n);
    	if (n == 1)
    	{
    		vector<int> temp;
    		temp.push_back(n);
    		result.push_back(temp);
    		return result;
    	}
    	int x1 = 0;
    	int x2 = n-1;
    	int y1 = 0;
    	int y2 = n-1;
    	int **num = new int*[n];//动态申请二维数组的方法！！！！！！！！！！
    	for (int i = 0; i < n; i++)
    		num[i] = new int[n];
    	int len = 1;
    	while (x1 <= x2 && y1 <= y2)
    	{
    		for (int i = y1; i <= y2; i++)
    		{
    			num[x1][i] = len;
    			len++;
    		}
    		for (int i = x1+1; i <= x2; i++)
    		{
    			num[i][y2] = len;
    			len++;
    		}
    		for (int i = y2-1; i >= y1; i--)
    		{
    			num[x2][i] = len;
    			len++;
    		}
    		for (int i = x2-1; i > x1; i--)
    		{
    			num[i][y1] = len;
    			len++;
    		}
    		x1++;x2--;y1++;y2--;
    	}
    	for (int i = 0; i < n; i++)
    	{
    		vector<int> temp;
    		for (int j = 0; j < n; j++)
    		{
    			temp.push_back(num[i][j]);
    		}
    		result.push_back(temp);
    	}
    	return result;
    }
};
/*int main(){
	int n = 2;
	Solution s;
	vector<vector<int> > result = s.generateMatrix(n);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
**/
