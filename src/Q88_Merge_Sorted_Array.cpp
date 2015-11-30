#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
        	return;
        if (nums1.size() == 0)
        {
        	nums1 = nums2;
        	return;
        }
        int p = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >=0 || j >= 0)
        {
        	if (j < 0)
        		return;
        	if (i < 0)
        	{
        		for (int k = j; k >=0; k--)
        		{
        			nums1[p] = nums2[k];
        			p --;
        		}
        		return;
        	}
        	if (nums1[i] <= nums2[j])
        	{
        		nums1[p] = nums2[j];
        		j --;
        		p --;
        	}
        	else
        	{
        		nums1[p] = nums1[i];
        		i --;
        		p --;
        	}
        }
    }
};
