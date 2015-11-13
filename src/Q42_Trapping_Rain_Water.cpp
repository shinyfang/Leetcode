#include<iostream>
#include<vector>
using namespace std;
/**
 * 超时！！！！！！！！！！！！！！！！！！！！！！！
 * class Solution {
public:
    int trap(vector<int>& height) {
    	if (height.size() < 3)//题意是最左端和最右端都不算
    		return 0;
    	int result = 0;
    	int len = height.size();
    	for (int i = 2; i < len; i++)//i表示一次比较多少个数，从3开始，3是最小的能围成一个水槽的数
    	{
    		//p1 p2分别表示要比较的起点和重点
    		for (int p1 = 0, p2 = p1+i; p2 < len; p1++, p2++)
    		{
    			int p = height[p1]>height[p2]?p2:p1;//选择较小的数比较
    			int j = p1+1;//从p1后面的数开始比较，直到p2前一个数
    			int max = height[j];//初始化中间的最大数，以便计算有效高度
    			while ((j < p2) && (height[j] < height[p]))
    			{
    				max = height[j]>max?height[j]:max;
    				j++;
    			}
    			if (j == p2)//中间的数都比p小，满足要求
    			{
    				result += (i-1)*(height[p]-max);
    			}
    		}
    	}
    	return result;
    }
};
**/

//找到最高的，然后从两头往最高处找，如果趋势升高则说明储存不了水，如果趋势下降那么可以储存水
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
	   //找到了标杆max_id处的max值
	   int result = 0;
	   int l_max = height[0];//初始化从左往右的局部最大值，为了便于计算高度
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
	   //从右往左找
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
