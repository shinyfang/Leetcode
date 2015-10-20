#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result;
    	if (nums.size() == 0)
    	{
    		result.push_back(-1);
    		result.push_back(-1);
    		return result;
    	}
    	//用两次二分查找，分别去找范围的左边界和右边界
    	int m = search(nums,0,nums.size()-1,target,true);
    	int n = search(nums,0,nums.size()-1,target,false);//true表示找最小的=target的index，false表示找最大的index
    	result.push_back(m);
    	result.push_back(n);
    	return result;
    }
    int search(vector<int>& nums, int p1, int p2, int target, bool flag)
    {
    	if (p1 <= p2)
    	{
    		int mid = (p1+p2)/2;
    		if (target == nums[mid])
    		{
    			cout<<"nums[mid]:"<<nums[mid]<<"=target"<<endl;
    			int pos = flag?search(nums,p1,mid-1,target,flag):search(nums,mid+1,p2,target,flag);
    			cout<<"pos:"<<pos<<" mid:"<<mid<<endl;
    			return (pos == -1)?mid:pos;
    		}
    		else if (nums[mid] < target)
    		{
    			search(nums,mid+1,p2,target,flag);
    		}
    		else
    			search(nums,p1,mid-1,target,flag);
    	}
    	else
    		return -1;
    }
};
/**int main(){
	vector<int>  nums;
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);
	int target = 8;
	Solution s;
	vector<int> result = s.searchRange(nums,target);
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";
	return 0;
}
**/
