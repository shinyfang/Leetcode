#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	//DFS找候选
	vector<vector<int> > r;
    vector<vector<int> > combinationSum3(int k, int n) {
    	if (k == 0) //k==0&&n==0时存在一组结果
    	{
    		if (n == 0)
    		{
    			vector<int> temp;
    			r.push_back(temp);
    		}
    		return r;
    	}
    	vector<int> res;
    	DFSsum3(res,1,k,n,0);
    	return r;
    }
    void DFSsum3(vector<int>& res, int begin, int k, int n, int sum)
    {
    	if (res.size() == k)
    	{
    		if (sum == n)
    			r.push_back(res);
    		return;
    	}
    	for (int i = begin; i <= 9; i ++)
    	{
    		if (sum + i <= n)
    		{
        		res.push_back(i);
    			DFSsum3(res,i+1,k,n,sum+i);
    			res.pop_back();
    		}
    		else
    			break;
    	}
    }
};
/**int main(){
	int k = 3;
	int n = 9;
	Solution s;
	vector<vector<int> > r = s.combinationSum3(k,n);
	for (int i = 0; i < r.size(); i ++)
	{
		for (int j = 0; j < r[i].size(); j ++)
			cout<<r[i][j];
		cout<<endl;
	}
	return 0;
}
**/
