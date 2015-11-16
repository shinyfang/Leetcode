#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	//���ݺ���
    	vector<int> result;
    	if (matrix.size() == 0)
    		return result;
    	if (matrix.size() == 1) //����ֻ��һ�����
    	{
    	    for (int i = 0; i < matrix[0].size(); i++)
    	        result.push_back(matrix[0][i]);
    	    return result;
    	}
    	if (matrix[0].size() == 1) //����ֻ��һ�����
    	{
    	    for (int i = 0; i < matrix.size(); i++)
    	        result.push_back(matrix[i][0]);
    	    return result;
    	}
    	//x1 x2 y1 y2�ֱ��ʾ�ĸ��߽�
    	int x1 = 0;
    	int y1 = 0;
    	int x2 = matrix.size()-1;//����
    	int y2 = matrix[0].size()-1;//����
    	while (x1 <= x2 && y1 <= y2)
    	{
    		//�Ϻ�
    		for (int i = y1; i <= y2; i++)
    			result.push_back(matrix[x1][i]);
    		for (int i = x1+1; i <= x2; i++)
    			result.push_back(matrix[i][y2]);
    		if (x1 != x2) //ע������Ҫ������
    		{
    		    for (int i = y2-1; i >= y1; i--)
    			result.push_back(matrix[x2][i]);
    		}
    		if (y1 != y2) //ע������Ҫ������
    		{
    		    for (int i = x2-1; i > x1; i--)
    			result.push_back(matrix[i][y1]);
    		}
    		x1++;x2--;y1++;y2--;
    	}
    	return result;
    }
};
