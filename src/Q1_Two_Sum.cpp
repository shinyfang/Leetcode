#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> out;
    	map<int,int> map;
    	for(int i=0;i<nums.size();i++){
    		map[nums[i]] = i+1;
    	}
    	for(int i=0;i<nums.size();i++){
    		if (map[target-nums[i]] > 0){
    			if(map[target-nums[i]]!=(i+1)){
    				int index1 = (i+1)>map[target-nums[i]]?map[target-nums[i]]:(i+1);
    				int index2 = (i+1)<map[target-nums[i]]?map[target-nums[i]]:(i+1);
    				out.push_back(index1);
    				out.push_back(index2);
    				break;
    			}
    		}
    	}
    	return out;
    }
};

/**int main(){
	vector<int> num;
	num.push_back(3);
	num.push_back(3);
	num.push_back(4);
	Solution s;
	vector<int> out = s.twoSum(num,6);
	for(int i=0;i<out.size();i++){
		cout<<out[i]<<endl;
	}
	return 0;
}**/
