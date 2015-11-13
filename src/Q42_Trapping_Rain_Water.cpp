#include<iostream>
#include<vector>
using namespace std;
/**
 * ��ʱ����������������������������������������������
 * class Solution {
public:
    int trap(vector<int>& height) {
    	if (height.size() < 3)//����������˺����Ҷ˶�����
    		return 0;
    	int result = 0;
    	int len = height.size();
    	for (int i = 2; i < len; i++)//i��ʾһ�αȽ϶��ٸ�������3��ʼ��3����С����Χ��һ��ˮ�۵���
    	{
    		//p1 p2�ֱ��ʾҪ�Ƚϵ������ص�
    		for (int p1 = 0, p2 = p1+i; p2 < len; p1++, p2++)
    		{
    			int p = height[p1]>height[p2]?p2:p1;//ѡ���С�����Ƚ�
    			int j = p1+1;//��p1���������ʼ�Ƚϣ�ֱ��p2ǰһ����
    			int max = height[j];//��ʼ���м����������Ա������Ч�߶�
    			while ((j < p2) && (height[j] < height[p]))
    			{
    				max = height[j]>max?height[j]:max;
    				j++;
    			}
    			if (j == p2)//�м��������pС������Ҫ��
    			{
    				result += (i-1)*(height[p]-max);
    			}
    		}
    	}
    	return result;
    }
};
**/

//�ҵ���ߵģ�Ȼ�����ͷ����ߴ��ң��������������˵�����治��ˮ����������½���ô���Դ���ˮ
class Solution {
public:
   int trap(vector<int>& height) {
	   if (height.size() < 3)
		   return 0;
	   int max_id = 0;
	   int max = height[0];
	   for (int i = 1; i < height.size(); i++)
	   {
		   if (height[i] > max)
		   {
			   max_id = i;
			   max = height[i];
		   }
	   }
	   //�ҵ��˱��max_id����maxֵ
	   int result = 0;
	   int l_max = height[0];//��ʼ���������ҵľֲ����ֵ��Ϊ�˱��ڼ���߶�
	   for (int i = 1; i < max_id; i++)
	   {
		   if (height[i] < l_max)
		   {
			   result += l_max-height[i];
		   }
		   else
		   {
			   l_max = height[i];
		   }
	   }
	   //����������
	   int r_max = height[height.size()-1];
	   for (int i = height.size()-2; i > max_id; i--)
	   {
		   if (height[i] < r_max)
		   {
			   result += r_max-height[i];
		   }
		   else
		   {
			   r_max = height[i];
		   }
	   }
	   return result;
   }
};
/**int main(){
	vector<int> height;
	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);
	Solution s;
	cout<<s.trap(height);
	return 0;
}
*/
