#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
    	if (ratings.size() == 0)
    		return 0;
    	int total = 1;
    	int start = 0;
    	int pre = 1;
    	for (int i = 1; i < ratings.size(); i++)
    	{
    		if (ratings[i] > ratings[i-1])//���������ֱ�Ӽ�1
    		{
    			start = i;
    			pre += 1;
    			total += pre;
    		}
    		else if (ratings[i] == ratings[i-1])//��ȿ��Իָ�1
    		{
    			start = i;
    			pre = 1;
    			total += pre;
    		}
    		else//�ݼ���Ҫ���ǣ����Ŷ��ٸ��ݼ�
    		{
    			int temp = 0;
    			while (i < ratings.size() && ratings[i] < ratings[i-1])//�ҵݼ����е�β��
    			{
    				temp ++;
    				i ++;
    			}
    			i --;//ע������Ҫ�ָ�i
    			if (pre <= temp)
    				total += (temp - pre + 1);//ǰ�������β��Ҫ����
    			total += (1+temp)*temp/2;//�ݼ������һ���˸�1����ǰ���ε����������͹�ʽ
    			pre = 1;
    		}
    	}
    	return total;
    }
};
