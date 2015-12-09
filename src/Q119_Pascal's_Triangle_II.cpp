#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> result;
    	if (rowIndex < 0)
    		return result;
    	vector<int> pre;
    	for (int i = 0; i <= rowIndex; i++)
    	{
    		result.push_back(1);
    		for (int j = 1; j <= i-1; j++)
    		{
    			result.push_back(pre[j-1]+pre[j]);
    		}
    		if (i > 0)
    			result.push_back(1);
    		pre = result;
    		result.clear();
    	}
    	return pre;
    }
};
/**int main(){
	int rowIndex = 3;
	Solution s;
	vector<int> result = s.getRow(rowIndex);
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";
	return 0;
}
**/
