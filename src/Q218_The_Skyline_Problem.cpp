#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
//考虑每个building的左边界和右边界
//遇到左边界大于现有的最大的边界，要把左边界加进来
//遇到右边界，要把相应的右边界弹出来，并且决定右边界是不是一个拐点
//当右边界是当前最大的高度，那么就是一个拐点，否则就不是
//set默认会自动排序，从小到大
class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
    	vector<pair<int,int> > r;
    	if (buildings.size() == 0)
    		return r;
    	vector<pair<int,int> > b;
    	for (int i = 0; i < buildings.size(); i ++)
    	{
    		b.push_back({buildings[i][0],-buildings[i][2]});
    		b.push_back({buildings[i][1],buildings[i][2]});//为了区别左边界和右边界，用-+来标记高度
    	}
    	sort(b.begin(),b.end());//默认按x从小到大的顺序
    	multiset<int> height;//保存现有的高度
    	height.insert(0);//初始高度是0
    	int pre = 0;//前一次最高的高度，为了找出遇到右边界时的拐点
    	int cur = 0;//当前最高的高度，为了确定新加入的高度是不是拐点
    	for (int i = 0; i < b.size(); i ++)
    	{
    		if (b[i].second < 0)
    			height.insert(-b[i].second);//遇到左边界要加入到高度set中，判断是否是拐点
    		else
    			height.erase(height.find(b[i].second));//遇到右边界要从高度中弹出，来判断弹出后和弹出前高度是否发生变化
    		cur = *height.rbegin();//取出最大的高度
    		if (pre != cur)//加入或者弹出高度前后最大高度发生变化，说明这个高度是拐点
    		{
    			r.push_back({b[i].first,cur});
    			//如果是左边界，说明加入了一个最高的高度的左边界，所以拐点的高度就是这个最高的高度
    			//如果是右边界，说明弹出了一个最高的高度的右边界，拐点的高度不是这个最高点，而是弹出后最高的高度cur
    			pre = cur;
    		}
    	}
    	return r;
    }
};
