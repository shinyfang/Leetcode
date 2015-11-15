#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
    	vector<vector<string> > result;
    	int *col = new int[n];
    	DFS(result,col,0,n); //col[i]��ʾ��ǰ��ȷ���ĵ�i��Q���к�
    	return result;
    }
    void DFS(vector<vector<string> > &result, int col[], int deep, int n)
    {
    	//�ҵ�deep��Ӧ�����ķ���Q
    	if (deep == n)
    	{
    		vector<string> ans;
    		for(int i = 0; i < n; i++)
    		{
    			string temp(n,'.');
    			temp[col[i]] = 'Q';
    			ans.push_back(temp);
    		}
    		result.push_back(ans);
    		return;
    	}
    	else
    	{
    		for (int i = 0; i < n; i++)
    		{
    			if (isvalid(col,deep,n,i))//�ж���֪col���飬��deep�н�Q���ڵ�i�����Ƿ���������
    			{
    				col[deep] = i;
    				DFS(result,col,deep+1,n);
    			}
    		}
    	}
    	return;
    }
    bool isvalid(int col[], int deep, int n, int k)
    {
    	for (int i = 0; i < deep; i++)
    	{
    		if (k == col[i] || (col[i]-i == k-deep) || (col[i]+i == k+deep))
    			return false;
    	}
    	return true;
    }
};
/**int main()
{
	Solution s;
	int n = 4;
	vector<vector<string> > result = s.solveNQueens(n);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			for (int t = 0; t < n; t++)
				cout<<result[i][j][t]<<" ";
			cout<<endl;
		}
		cout<<endl;
		cout<<endl;
	}
	return 0;
}
**/
