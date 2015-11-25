#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	//杨氏矩阵
    	int m = matrix.size();
    	if (m == 0)
    		return false;
    	int n = matrix[0].size();
    	if (n == 0 || target < matrix[0][0] || target > matrix[m-1][n-1])
    		return false;
    	int i = 0;
    	int j = n-1;//初始化指针在右上角
    	while (i < m && j >= 0)
    	{
    		if (matrix[i][j] == target)
    			return true;
    		else if (matrix[i][j] < target)
    			i++;
    		else
    			j--;
    	}
    	return false;
    }
};
/**int main(){
	vector<vector<int> > matrix;
	int target = 1;
	Solution s;
	cout<<s.searchMatrix(matrix,target);
	return 0;
}
**/
