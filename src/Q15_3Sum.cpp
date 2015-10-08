#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > result;
    	sort(nums.begin(),nums.end());
    	for(int i=0;i<nums.size();i++){
    		if ( i>0 && nums[i] == nums[i-1])
    			continue;
    		int a1 = nums[i];
    		cout<<"a1="<<a1<<endl;
    		int target = 0 - a1;
    		cout<<"target="<<target<<endl;
    		for(int l = i + 1, r = nums.size()-1; l < r;){
    			while (l>i+1 && nums[l]==nums[l-1])
    				l++;
    			if (l>=r)
    				break;
    			while (r<nums.size()-1 && nums[r]==nums[r+1])
    				r--;
    			if (r<=l)
    				break;
    			if ((nums[l]+nums[r]) == target){
    				cout<<nums[l]<<" "<<nums[r]<<endl;
    				vector<int> temp;
    				temp.push_back(a1);
    				temp.push_back(nums[l]);
    				temp.push_back(nums[r]);
    				result.push_back(temp);
    				l++;r--;
    			}
    			else if ((nums[l]+nums[r]) < target){
    				l++;
    			}
    			else
    				r--;
    		}
    	}
    	return result;
    }
};
int main(){
	Solution s;
	vector<int> nums;
	int n1 = -5;
	nums.push_back(n1);
	int n2 = 1;
	nums.push_back(n2);
	int n3 = 1;
	nums.push_back(n3);
	int n4 = 1;
	nums.push_back(n4);
	int n5 = 4;
	nums.push_back(n5);
	int n6 = 4;
	nums.push_back(n6);
	int n7 = 4;
	nums.push_back(n7);
	vector<vector<int> > r = s.threeSum(nums);
	for (int i=0;i<r.size();i++){
		for (int j = 0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
