#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool comp(const Interval& a, const Interval& b)//����д��const����ʽ������sort����
{
	if (a.start == b.start)
		return a.end<b.end;
	return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> result;
    	if (intervals.size() == 0)
    		return result;
    	sort(intervals.begin(),intervals.end(),comp);
    	Interval current = intervals[0];
    	for (int i = 1; i < intervals.size(); i++)
    	{
    		if (intervals[i].start > current.end)//�����һ����Χ�����˴�ʱ�����Χ�����ʱ�ķ�Χ���Լ���
    		{
    			result.push_back(current);
    			current = intervals[i];
    		}
    		else
    		{
    			current.end = current.end>intervals[i].end?current.end:intervals[i].end;
    			//��һ����Χ��start�ڴ�ʱ��Χ֮�䣬ȡ�ϴ��end��Ϊ��ʱ��end����
    		}
    	}
    	result.push_back(current);
    	return result;
    }
};
/**int main(){
	vector<Interval> intervals;
	Interval a(1,5);
	Interval b(5,5);
	//Interval c(4,10);
	//Interval d(5,18);
	intervals.push_back(a);
	intervals.push_back(b);
	//intervals.push_back(c);
	//intervals.push_back(d);
	Solution s;
	vector<Interval> result = s.merge(intervals);
	for (int i = 0; i < result.size(); i++)
	{
		cout<<result[i].start<<" "<<result[i].end<<endl;
	}
	return 0;
}
**/
