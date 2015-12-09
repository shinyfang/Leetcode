#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {//直接用数学方法计算会超出范围
    	vector<vector<int> > result;
    	if (numRows == 0)
    		return result;
    	for (int i = 1; i <= numRows; i++)
    	{
    		vector<int> temp;
    		temp.push_back(1);
    		for (int j = 1; j < i - 1; j++)
    		{
    			temp.push_back(result[i-2][j-1]+result[i-2][j]);
    		}
    		if (i > 1)
    			temp.push_back(1);
    		result.push_back(temp);
    	}
    	return result;
    }
};
/**int main(){
	int numRows = 5;
	Solution s;
	vector<vector<int> > result = s.generate(numRows);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
**/
