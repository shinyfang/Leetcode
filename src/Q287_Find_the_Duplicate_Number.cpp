#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	//n+1������Χ��1-n����û���ظ�<=i�ĸ���Ϊi�������ظ�<=i�ĸ�������i
    	int l = 1;
    	int r = nums.size()-1;
    	while (l < r)
    	{
    		int mid = l + (r - l) / 2;
    		int count = 0;
    		for (int i = 0; i < nums.size(); i ++)
    			count += (nums[i]<=mid?1:0);
    		if (count <= mid)
    			l = mid + 1;
    		else
    			r = mid;
    	}
    	return l;
    }
};
