#include<iostream>
#include<vector>
using namespace std;
class NumMatrix {
public:
	vector<vector<int> > m;
    NumMatrix(vector<vector<int> > &matrix) {
    	if (matrix.size() == 0 || matrix[0].size() == 0)
    		return;
    	m = matrix;
        for (int i = 1; i < matrix.size(); i ++)
        	m[i][0] = m[i-1][0] + matrix[i][0];
        for (int i = 1; i < matrix[0].size(); i ++)
        	m[0][i] = m[0][i-1] + matrix[0][i];
        for (int i = 1; i < matrix.size(); i ++)
        {
        	for (int j = 1; j < matrix[0].size(); j ++)
        	{
        		m[i][j] = m[i-1][j] + m[i][j-1] + matrix[i][j] - m[i-1][j-1];
        	}
        }
        for (int i = 0; i < m.size(); i ++)
        {
        	for (int j = 0; j < m[0].size(); j ++)
        		cout<<m[i][j]<<" ";
        	cout<<endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
        	return m[row2][col2];
        else if (row1 == 0 && col1 > 0)
        	return m[row2][col2]-m[row2][col1-1];
        else if (row1 > 0 && col1 == 0)
        	return m[row2][col2]-m[row1-1][col2];
        else
        	return m[row2][col2]-m[row2][col1-1]-m[row1-1][col2]+m[row1-1][col1-1];
    }
};
int main(){
	vector<vector<int> > matrix;
	vector<int> a1;
	a1.push_back(3);
	a1.push_back(0);
	a1.push_back(1);
	a1.push_back(4);
	a1.push_back(2);
	vector<int> a2;
	a2.push_back(5);
	a2.push_back(6);
	a2.push_back(3);
	a2.push_back(2);
	a2.push_back(1);
	vector<int> a3;
	a3.push_back(1);
	a3.push_back(2);
	a3.push_back(0);
	a3.push_back(1);
	a3.push_back(5);
	vector<int> a4;
	a4.push_back(4);
	a4.push_back(1);
	a4.push_back(0);
	a4.push_back(1);
	a4.push_back(7);
	vector<int> a5;
	a5.push_back(1);
	a5.push_back(0);
	a5.push_back(3);
	a5.push_back(0);
	a5.push_back(5);
	matrix.push_back(a1);
	matrix.push_back(a2);
	matrix.push_back(a3);
	matrix.push_back(a4);
	matrix.push_back(a5);
	NumMatrix numMatrix(matrix);
	//numMatrix.sumRegion(0, 1, 2, 3);
	//numMatrix.sumRegion(1, 2, 3, 4);
	return 0;
}
