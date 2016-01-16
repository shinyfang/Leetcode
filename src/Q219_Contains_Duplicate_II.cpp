#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	if (nums.size() == 0 || k == 0)
    		return false;
    	int i = 0;
    	int j = 1;
    	set<int> m;//��set���洢k��Χ�ڻ�����ͬ����
    	//��˫ָ����Ȧ��k�ķ�Χ
    	m.insert(nums[i]);
    	while (j < nums.size())
    	{
    		if (j - i > k)
    		{
    			m.erase(nums[i]);
    			i ++;
    		}
    		while (j - i <= k && j < nums.size())
    		{
    			if (m.find(nums[j]) != m.end())
    				return true;
    			m.insert(nums[j]);
    			j ++;
    		}
    	}
    	return false;
    }
};
