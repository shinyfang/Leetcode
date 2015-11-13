#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //O(N)˵��ֻ����һ��ѭ��
    	//�ҵ�һ����������1��ʼ������������nums�������nums.size()��ֵ���ÿ���λ����
    	//��ֵi�ָ���index=i-1��λ���ϣ���Ϊ����Щ�����������ǰ�˳������Ӧ��������
    	if (nums.size() == 0)
    		return 1;
    	int len = nums.size();//�����ܳ��ܵ������ֵnums[len-1]=len
    	for (int i = 0; i < len; i++)
    	{
    		//Ҫ�������������0С�ڵ���len
    		while (nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i])
    			swap(nums[i],nums[nums[i]-1]);
    	}
    	for (int i = 0; i < len; i++)
    	{
    		if (nums[i] != i+1)
    			return i+1;
    	}
    	return len+1;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(1);
	Solution s;
	cout<<s.firstMissingPositive(nums);
	return 0;
}
**/
