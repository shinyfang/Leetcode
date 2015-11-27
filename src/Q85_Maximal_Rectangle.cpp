#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char> >& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int result = 0;
		for (int i = 0; i < matrix.size(); i++) {
			vector<int> temp;
			for (int j = 0; j < matrix[i].size(); j++) {
				int sum = 0;
				for (int k = i; k >= 0; k--) {
					if (matrix[k][j] == '0')
						break;
					else
						sum++;
				}
				temp.push_back(sum);
			}
		int temp1 = largestRectangleArea(temp);
		result = temp1>result?temp1:result;
	}
	return result;
}
int largestRectangleArea(vector<int>& height) {
	if (height.size() == 0)
		return 0;
	if (height.size() == 1)
		return height[0];
	int result = 0;
	vector<pair<int, int> > h;
	//h.push_back(make_pair<int, int>(height[0], 0)); //这里提交的时候编译错误？？
	pair<int, int> temp1(height[0],0);//这样提交正确
	h.push_back(temp1);
	int p = 1;
	while (p < height.size()) {
		pair<int, int> temp(height[p], p);
		while (h.size() > 0 && h[h.size() - 1].first >= height[p]) {
			result =
					h[h.size() - 1].first * (p - h[h.size() - 1].second)
							> result ?
							h[h.size() - 1].first
									* (p - h[h.size() - 1].second) :
							result;
			temp.second = h[h.size() - 1].second;
			h.pop_back();
		}
		h.push_back(temp);
		p++;
	}
	while (h.size() > 0) {
		result =
				h[h.size() - 1].first * (height.size() - h[h.size() - 1].second)
						> result ?
						h[h.size() - 1].first
								* (height.size() - h[h.size() - 1].second) :
						result;
		h.pop_back();
	}
	return result;
}
};
