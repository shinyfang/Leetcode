#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = nums[0]+nums[1]+nums[2];
		sort(nums.begin(),nums.end());
		for (int i = 0; i < nums.size() - 2; i++){
			cout<<"nums[i]="<<nums[i]<<endl;
			int l = i + 1;
			int r = nums.size() - 1;
			//在指针变动之前计算result
			while(l<r){
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == target)
					return target;
				if (abs(target-sum)<abs(target-result))
					result = sum;
				if (sum < target)
					l++;
				else
					r--;
			}
		}
		return result;
	}
};
/**int main() {
	Solution s;
	vector<int> nums;
	int n1 = 1;
	int n2 = 1;
	int n3 = -1;
	//int n4 = 2;
	nums.push_back(n1);
	nums.push_back(n2);
	nums.push_back(n3);
	//nums.push_back(n4);
	int target = 2;
	cout << s.threeSumClosest(nums, target);
	return 0;
}
**/
