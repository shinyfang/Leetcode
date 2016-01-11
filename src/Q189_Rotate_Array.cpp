#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	if (nums.size() < 2 || k == 0 || k == nums.size())
    		return;
    	rotate2(nums,0,nums.size()-k%nums.size()-1);
    	rotate2(nums,nums.size()-k%nums.size(),nums.size()-1);
    	rotate2(nums,0,nums.size()-1);
    }
    void rotate2(vector<int>& nums, int begin, int end)
    {
    	if (begin == end)
    		return;
    	while (begin < end)
    	{
    		int temp = nums[begin];
    		nums[begin] = nums[end];
    		nums[end] = temp;
    		begin ++;
    		end --;
    	}
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	Solution s;
	s.rotate(nums,3);
	for (int i = 0; i < nums.size(); i++)
		cout<<nums[i];
	return 0;
}
**/
