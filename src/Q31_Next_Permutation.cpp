#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (nums[i] >= nums[i+1] && i >= 0)
        	i--;
        //从后往前找到前面的数大于后面的数的i
        if (i < 0)
        {
        	//说明nums已经是最大的数了，返回最小的数
        	sort(nums.begin(),nums.end());
        }
        else
        {
        	//找到i，再从后往前找到第一个比i大的数j，交换，然后把i后面的数排序为最小的序列
        	int j = nums.size()-1;
        	cout<<"i:"<<i<<" j:"<<j<<endl;
        	while (nums[j] <= nums[i])//找到从后往前第一个比i大的数，交换
        		j--;
        	int temp = nums[i];
        	nums[i] = nums[j];
        	nums[j] = temp;
        	sort(nums.begin()+i+1,nums.end());//交换后对i之后的数重新进行最小排序
        }
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	Solution s;
	s.nextPermutation(nums);
	cout<<nums[0]<<" "<<nums[1];
	return 0;
}
**/
