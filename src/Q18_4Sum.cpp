#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4)
        	return result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-3; i++){
        	if (i > 0 && nums[i] == nums[i-1])
        		continue;
        	for (int j = i+1; j < nums.size()-2; j++){
        		if (j > i+1 && nums[j] == nums[j-1])
        			continue;
        		cout<<"nums[i]:"<<nums[i]<<" "<<"nums[j]:"<<nums[j]<<" ";
        		int l = j+1;
        		int r = nums.size()-1;
        		while(l<r){
        			cout<<"nums[l]:"<<nums[l]<<" "<<"nums[r]:"<<nums[r]<<" ";
        			if (l > j+1 && nums[l] == nums[l-1]){
        				l++;
        				continue;
        			}
        			if (r < nums.size()-1 && nums[r] == nums[r+1]){
        				r--;
        				continue;
        			}
					int sum = nums[i]+nums[j]+nums[l]+nums[r];
					cout<<"sum:"<<sum<<endl;
					if (sum == target){
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[l]);
						temp.push_back(nums[r]);
						result.push_back(temp);
						cout<<"in!"<<endl;
						l++;
						r--;
					}
					else if (sum < target){
						l++;
					}
					else
						r--;
        		}
        	}
        }
        return result;
    }
};
/**int main(){
	Solution s;
	int n1 = -3;
	int n2 = -2;
	int n3 = -1;
	int n4 = 0;
	int n5 = 0;
	int n6 = 1;
	int n7 = 2;
	int n8 = 3;
	vector<int> nums;
	nums.push_back(n1);
	nums.push_back(n2);
	nums.push_back(n3);
	nums.push_back(n4);
	nums.push_back(n5);
	nums.push_back(n6);
	nums.push_back(n7);
	nums.push_back(n8);
	int target = 0;
	vector<vector<int> > result = s.fourSum(nums,target);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
**/
