#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	//������������к�
    	int max = nums[0];
    	int sum = nums[0];//��¼����i������ǰһ����Ϊֹ������
    	for (int i = 1; i < nums.size(); i++)
    	{
    		max = sum>max?sum:max;
    		if (sum <= 0)
    			sum = nums[i];//���֮ǰ�ĺ��Ǹ������Ǽ��㵽iΪֹ����������о�ֻ���ǵ�i��������
    		else
    			sum += nums[i];//������Լ��������
    	}
    	max = sum>max?sum:max;
    	return max;
    }
};
/**int main(){
	Solution s;
	vector<int> num;
	num.push_back(-2);
	num.push_back(1);
	num.push_back(-3);
	num.push_back(4);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-5);
	num.push_back(4);
	cout<<s.maxSubArray(num);
	return 0;
}
**/
