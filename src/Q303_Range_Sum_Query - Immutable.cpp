#include<iostream>
#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> num;
    NumArray(vector<int> &nums) {
        if (nums.size() == 0)
            return;
        num.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i ++)
            num.push_back(num[num.size()-1]+nums[i]);
    }
    int sumRange(int i, int j) {
        return num[j]-num[i-1];
    }
};
