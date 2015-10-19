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
        //�Ӻ���ǰ�ҵ�ǰ��������ں��������i
        if (i < 0)
        {
        	//˵��nums�Ѿ����������ˣ�������С����
        	sort(nums.begin(),nums.end());
        }
        else
        {
        	//�ҵ�i���ٴӺ���ǰ�ҵ���һ����i�����j��������Ȼ���i�����������Ϊ��С������
        	int j = nums.size()-1;
        	cout<<"i:"<<i<<" j:"<<j<<endl;
        	while (nums[j] <= nums[i])//�ҵ��Ӻ���ǰ��һ����i�����������
        		j--;
        	int temp = nums[i];
        	nums[i] = nums[j];
        	nums[j] = temp;
        	sort(nums.begin()+i+1,nums.end());//�������i֮��������½�����С����
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
