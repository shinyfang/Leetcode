#include<iostream>
#include<vector>
using namespace std;
//��Ŀ��˼�Ƿ�����val��ͬ�����ĳ��ȣ����һ���nums����ǰlen�����ǲ�����val��ͬ
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0, j = nums.size()-1; i <= j;)
        {
        	if (nums[i] != val)
        	{
        		len++;
        		i++;
        	}
        	else
        	{
        		nums[i] = nums[j];
        		j--;
        	}
        }
        return len;
    }
};
