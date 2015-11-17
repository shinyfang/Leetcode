#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() :
			start(0), end(0) {
	}
	Interval(int s, int e) :
			start(s), end(e) {
	}
};
bool comp1(const Interval& a, const Interval& b)//����д��const����ʽ������sort����
{
	if (a.start == b.start)
		return a.end<b.end;
	return a.start<b.start;
}
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		if (intervals.size() == 0)
		{
			result.push_back(newInterval);
			return result;
		}
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), comp1);
		Interval current = intervals[0];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start > current.end) //�����һ����Χ�����˴�ʱ�����Χ�����ʱ�ķ�Χ���Լ���
			{
				result.push_back(current);
				current = intervals[i];
			} else {
				current.end =
						current.end > intervals[i].end ?
								current.end : intervals[i].end;
				//��һ����Χ��start�ڴ�ʱ��Χ֮�䣬ȡ�ϴ��end��Ϊ��ʱ��end����
			}
		}
		result.push_back(current);
		return result;
	}
};
/**int main() {
	vector<Interval> intervals;
	Interval a(1, 3);
	Interval b(6, 7);
	Interval c(2, 5);
	//Interval d(5,18);
	intervals.push_back(a);
	intervals.push_back(b);
	//intervals.push_back(c);
	//intervals.push_back(d);
	Solution s;
	vector<Interval> result = s.insert(intervals, c);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].start << " " << result[i].end << endl;
	}
	return 0;
}
**/
