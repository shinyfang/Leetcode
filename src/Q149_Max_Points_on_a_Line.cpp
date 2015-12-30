#include<iostream>
#include<vector>
#include<climits>
#include<map>
#include<unordered_map>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	if (points.size() == 0)
    		return 0;
    	map<double,int> count;
    	//unordered_map<double,int> count;提交这个
    	int max = 0;
    	for (int i = 0; i < points.size(); i++)
    	{
    		count.clear();
    		int dup = 1;//自身也算1个,还计算与本身重合的个数
    		for (int j = 0; j < points.size(); j++)
    		{
    			if (i == j)
    				continue;
    			if (points[i].x == points[j].x && points[i].y == points[j].y)
    			{
    				dup ++;
    				continue;
    			}
    			double k = (points[i].x == points[j].x?INT_MAX:double(points[j].y-points[i].y)/(points[j].x-points[i].x));
    			//除数是整数，结果是整数，所以要加上double，不然结果不对！！！
    			count[k] ++;
    		}
    		if (count.empty())
    			max = dup;
    		for (map<double,int>::iterator it = count.begin(); it != count.end(); it ++)
    			max = it->second+dup>max?it->second+dup:max;
    	}
    	return max;
    }
};
