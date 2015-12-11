#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {//��ͨ��vector���һᳬʱ���뵽��hash��map��unordered_map������
    	if (nums.size() == 0)
    		return 0;
    	int longest = 0;
    	//unordered_map<int, bool> used;�ύ��ʱ�������
    	map<int, bool> used;
    	for (int i = 0; i < nums.size(); i++)
    		used[nums[i]] = false;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if (!used[nums[i]])
    		{
    			int max = 1;
    			used[nums[i]] = true;
    			for (int j = nums[i] + 1; used.find(j) != used.end(); j++)
    			{
    				max ++;
    				used[j] = true;
    			}
    			for (int j = nums[i] - 1; used.find(j) != used.end(); j--)
    			{
    				max ++;
    				used[j] = true;
    			}
    			longest = max>longest?max:longest;
    		}
    	}
    	return longest;
    }
};
/**int main(){
	vector<int> nums;
	nums.push_back(100);
	nums.push_back(4);
	nums.push_back(200);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	Solution s;
	cout<<s.longestConsecutive(nums);
	return 0;
}
**/
