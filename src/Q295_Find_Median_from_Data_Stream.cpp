#include<iostream>
#include<queue>
using namespace std;
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
    	//新加入的数先放入较小的数组里，将排序后最大的元素放入较大的数组里排序，保证顶端的元素的中位数
    	maxH.push(num);
    	int temp = maxH.top();
    	maxH.pop();
    	minH.push(temp);
    	if (maxH.size() < minH.size())
    	{
    		temp = minH.top();
    		minH.pop();
    		maxH.push(temp);
    	}
    }

    // Returns the median of current data stream
    double findMedian() {
    	if (maxH.size() == 0 && minH.size() == 0)
    		return 0.0;
    	//如果两者的size相等，说明中位数是两者平均值
    	if (maxH.size() == minH.size())
    		return (double(maxH.top()+minH.top())/2);
    	else
    		return (maxH.size()>minH.size()?maxH.top():minH.top());
    }
private:
    //最大堆最小堆实现，最大堆是按照从小到大的顺序排列，存储的是较小的一部分数；最小堆是按照从大到小的顺序排列，存储的是较大的一部分数
    //计算中位数时，两个堆顶端的元素可能是中位数
    priority_queue<int,vector<int>,less<int> >  maxH;
    priority_queue<int,vector<int>,greater<int> > minH;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
