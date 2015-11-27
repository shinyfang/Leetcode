#include<iostream>
#include<vector>
using namespace std;
/**
 * 超时！！！！！！！！！！！
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    	if (height.size() == 0)
    		return 0;
    	int result = 0;
    	for (int i = 0; i < height.size(); i++)
    	{
    		if (height[i] == 0)
    		{
    			continue;
    		}
    		int sum = 1;
    		int l = i - 1;
    		while (l >= 0 && height[l] >= height[i])
    		{
    			sum ++;
    			l --;
    		}
    		int r = i + 1;
    		while (r < height.size() && height[r] >= height[i])
    		{
    			sum ++;
    			r ++;
    		}
    		result = sum*height[i]>result?sum*height[i]:result;
    	}
    	return result;
    }
};
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    	if (height.size() == 0)
    		return 0;
    	if (height.size() == 1)
    		return height[0];
    	int result = 0;
    	vector<pair<int, int> > h;
    	h.push_back(make_pair<int, int>(height[0],0));//这里提交的时候编译错误？？
    	//pair<int, int> temp1(height[0],0);//这样提交正确
    	//h.push_back(temp1);
    	int p = 1;
    	while (p < height.size())
    	{
    		pair<int, int> temp(height[p],p);
    		while (h.size() > 0 && h[h.size()-1].first >= height[p])
    		{
    			result = h[h.size()-1].first*(p-h[h.size()-1].second)>result?h[h.size()-1].first*(p-h[h.size()-1].second):result;
    			temp.second = h[h.size()-1].second;
    			h.pop_back();
    		}
    		h.push_back(temp);
    		p ++;
    	}
    	while (h.size() > 0)
    	{
    		result = h[h.size()-1].first*(height.size()-h[h.size()-1].second)>result?h[h.size()-1].first*(height.size()-h[h.size()-1].second):result;
    		h.pop_back();
    	}
    	return result;
    }
};
/**int main(){
	vector<int> height;
	height.push_back(2);
	height.push_back(3);
	height.push_back(5);
	//height.push_back(6);
	//height.push_back(2);
	//height.push_back(3);
	Solution s;
	cout<<s.largestRectangleArea(height);
	return 0;
}
**/
