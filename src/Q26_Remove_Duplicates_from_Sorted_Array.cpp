#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() == 0)
    		return 0;
    	if (nums.size() == 1)
    		return 1;
    	int p1 = 0;
    	for (int p2 = 1; p2 < nums.size(); p2++){
    		if (nums[p1] == nums[p2])
    		{
    			while (nums[p2] == nums[p1] && p2 < nums.size())
    				p2++;
    			if (p2 == nums.size())
    				return (p1+1);
    		}
    		nums[p1+1] = nums[p2];
    		p1++;
    	}
    	return (p1+1);
    }
};
/**int main(){
	Solution s;
	vector<int> nums;
	int n1 = 1;
	int n2 = 1;
	int n3 = 2;
	nums.push_back(n1);
	nums.push_back(n2);
	nums.push_back(n3);
	cout<<s.removeDuplicates(nums);
	return 0;
}
**/
