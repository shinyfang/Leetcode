#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		int p1 = 0; //指向0
		int p2 = 0; //指向其他数字
		while (p1 < nums.size() && p2 < nums.size()) {
			while (p1 < nums.size() && nums[p1] != 0)
				p1++;
			while (p2 < nums.size() && nums[p2] == 0)
				p2++;
			if (p1 == nums.size() || p2 == nums.size())
				return;
			if (p1 < p2)
			{
				nums[p1] = nums[p2];
				nums[p2] = 0;
			}
			else
				p2 ++;
		}
	}
};
