#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
    	int step = 0;
    	int current = 0;
    	int next = 0;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if (i > current)
    		{
    			//ÿ��Ҫ����currentʱ��������º�current�Բ�����˵����ʱ�Ѿ��߲����ˣ�Ҳ��Զ�߲����յ���
    			if (current == next)
    				return false;
    			//<current��Χ�ڵĸ���step�������ߵ���<current����ֻ������һ��
    			step++;
    			current = next;
    		}
    		//ÿ�ζ�Ҫ�������ߵ���Զ����
    		next = (i+nums[i]>next)?(i+nums[i]):next;
    		if (next+nums[next] >= nums.size())
    			return true;
    	}
    	return true;
	}
};
/**int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	//nums.push_back(1);
	//nums.push_back(0);
	//nums.push_back(4);
	Solution s;
	cout<<s.canJump(nums);
	return 0;
}
**/
