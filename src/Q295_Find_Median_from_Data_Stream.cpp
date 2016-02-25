#include<iostream>
#include<queue>
using namespace std;
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
    	//�¼�������ȷ����С������������������Ԫ�ط���ϴ�����������򣬱�֤���˵�Ԫ�ص���λ��
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
    	//������ߵ�size��ȣ�˵����λ��������ƽ��ֵ
    	if (maxH.size() == minH.size())
    		return (double(maxH.top()+minH.top())/2);
    	else
    		return (maxH.size()>minH.size()?maxH.top():minH.top());
    }
private:
    //������С��ʵ�֣������ǰ��մ�С�����˳�����У��洢���ǽ�С��һ����������С���ǰ��մӴ�С��˳�����У��洢���ǽϴ��һ������
    //������λ��ʱ�������Ѷ��˵�Ԫ�ؿ�������λ��
    priority_queue<int,vector<int>,less<int> >  maxH;
    priority_queue<int,vector<int>,greater<int> > minH;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
