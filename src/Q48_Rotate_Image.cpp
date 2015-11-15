#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
    	int len = matrix.size(); //len*len长度的矩阵
    	int begin = 0;
    	int end = len-1;
    	for (int begin = 0; begin <= end; begin++)
    		//旋转开始的坐标
    	{
    		if (begin == end)
    			return;
			for (int i = begin; i < end; i++)
			{
				cout<<"i="<<i<<endl;
				int num = 4;
				int temp1 = matrix[begin][i];
				int x = begin;
				int y = i;
				while(num--)//正方形每次旋转四次
				{
					int temp2 = matrix[y][len-1-x];
					//temp1记录正在旋转的数字，temp2记录下次旋转的数字
					matrix[y][len-1-x] = temp1;
					temp1 = temp2;
					int temp3 = x;//记得把旋转的坐标更新
					x = y;
					y = len-1-temp3;
				}
			}
			end--;
    	}
    }
};
/**int main()
{
	Solution s;
	vector<vector<int> >matrix;
	vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(2);
	matrix.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(3);
	temp2.push_back(4);
	matrix.push_back(temp2);
	s.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j <matrix[i].size(); j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
**/
