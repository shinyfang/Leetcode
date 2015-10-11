#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
    	//不能倾斜，只能是长方形，所以两条边取较短的一条
    	//双指针往中间靠拢
    	if (height.size() < 2)
    		return 0;
    	int result = (height.size()-1)*(height[0]<height[height.size()-1]?height[0]:height[height.size()-1]);
    	cout<<"result:"<<result<<endl;
    	for(int i = 0, j = height.size()-1; i<j;){
    		if (height[i] <= height[j]){
    			int temp = height[i];
				while (height[i] <= temp && i < j){
					i++;
				}
    		}else{
    			int temp = height[j];
    			while(height[j] <= temp && i < j)
    				j--;
    		}
    		if (i == j)
    			return result;
    		result = (j-i)*(height[i]<height[j]?height[i]:height[j])>result?((j-i)*(height[i]<height[j]?height[i]:height[j])):result;
    	}
    	return result;
    }
};
/**int main(){
	vector<int> height;
	int n1 = 1;
	int n2 = 2;
	int n3 = 4;
	int n4 = 3;
	//int n5 = 4;
	height.push_back(n1);
	height.push_back(n2);
	height.push_back(n3);
	height.push_back(n4);
	//height.push_back(n5);
	Solution s;
	cout<<s.maxArea(height);
	return 0;
}
**/
