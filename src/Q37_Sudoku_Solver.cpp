#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
	void solveSudoku(vector<vector<char> >& board) {
		int b[9]; //����
		int c[9]; //��������9������
		for (int i = 0; i < 9; i += 3) //ÿ��һ������һ����
		{
			for (int j = 0; j < 9; j += 3)
			{
				int temp1 = i;
				int temp2 = j;
				int k1 = 3;
				memset(c, 0, sizeof(c) * 9);//�����γ�ʼ��
				while (k1--)
				{//��������9������
					temp2 = j;
					int k2 = 3;
					while (k2--)
					{
						if (board[temp1][temp2] != '.')
						{
							c[board[temp1][temp2]-'1'] = 1;
						}
						temp2++;
					}
					temp1++;
				}
				temp1 = i;
				temp2 = j;
				for (int t1 = 0; t1 < 3; t1++)
				{
					for (int t2 = 0; t2 < 3; t2++)
					{
						for (int t = 0; t < 9; t++)
						{
							if (board[temp2+t2][t1] != '.')
							{

							}
						}
					}
				}
			}
		}
	}
};
