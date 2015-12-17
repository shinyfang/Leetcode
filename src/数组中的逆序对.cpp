#include<iostream>
#include<vector>
using namespace std;
//归并，算逆序对，排序
class Solution{
public:
	int InversePairs(vector<int> nums)
	{
		if (nums.size() <= 1)
			return 0;
		vector<int> copy(nums);//copy用作之后排序
		return InPairs(nums,copy,0,nums.size()-1);
	}
	int InPairs(vector<int>& nums, vector<int>& copy, int begin, int end)
	{
		if (begin == end)
		{
			copy[begin] = nums[begin];//表示不交换位置
			return 0;
		}
		int length = (end-begin)/2;
		int left = InPairs(nums,copy,begin,begin+length);
		int right = InPairs(nums,copy,begin+length+1,end);//递归计算左右两边小数组内的逆序对，并且在数组内已经排序
		int i = begin + length;//左数组的尾
		int j = end;//右数组的尾巴，开始计算两个数组间的逆序对
		int new_index = end;//排序的index，从大到小排序，所以index初始化为end
		int count = 0;//数组间的逆序对
		while (i >= begin && j >= begin + length + 1)//有可比较的ij
		{
			if (nums[i] > nums[j])
			{
				//找到了逆序对
				count += (j-begin-length);//i会不断变化，而这里指的是右数组能配对的数量
				copy[new_index--] = nums[i--];//更新copy，写入较大的数
			}
			else
			{
				copy[new_index--] = nums[j--];
			}
		}
		//此时还有最小的数未写入
		for (;i >= begin; i--)
			copy[new_index--] = nums[i];
		for (; j >= begin + length + 1; j--)
			copy[new_index--] = nums[j];
		nums = copy;//每次都要更新nums
		return (left+right+count);
	}
};
/**int main(){
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);
	Solution s;
	cout<<s.InversePairs(nums);
	return 0;
}
**/
