#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
//支持快速查找set multiset 插入删除查找都在logn时间内完成 并且元素都是从小到大排序好的
//圈定k范围内的数，每次新加入一个数时查找是否有符合差值为t的情况
//考虑到可能有正数与负数之间做差会超过最大值，用 long long存储
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (nums.size() < 2 || k == 0 || t < 0)
    		return false;
    	multiset<long long> m;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if (m.size() > k)//当存了k个数时，这k个数都是可能与第i个数匹配的数，所以只能大于k时才弹出第一个数
    			m.erase(m.find(nums[i-k-1]));
    		//继续比较当前的数
    		multiset<long long>::iterator it = m.lower_bound(nums[i]);//lower_bound返回大于等于这个数的第一个元素的位置
    		if (it != m.end() && abs(*it - nums[i]) <= t)
    			return true;
    		it = m.upper_bound(nums[i]);//返回大于这个数的第一个元素的位置，但此时我们要找的是小于这个是的第一个元素的位置
    		if (it != m.begin() && abs(*(--it) - nums[i]) <= t)
    			return true;
    		m.insert(nums[i]);
    	}
    	return false;
    }
};
