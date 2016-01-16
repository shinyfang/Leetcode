#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
//����ÿ��building����߽���ұ߽�
//������߽�������е����ı߽磬Ҫ����߽�ӽ���
//�����ұ߽磬Ҫ����Ӧ���ұ߽絯���������Ҿ����ұ߽��ǲ���һ���յ�
//���ұ߽��ǵ�ǰ���ĸ߶ȣ���ô����һ���յ㣬����Ͳ���
//setĬ�ϻ��Զ����򣬴�С����
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
    		b.push_back({buildings[i][1],buildings[i][2]});//Ϊ��������߽���ұ߽磬��-+����Ǹ߶�
    	}
    	sort(b.begin(),b.end());//Ĭ�ϰ�x��С�����˳��
    	multiset<int> height;//�������еĸ߶�
    	height.insert(0);//��ʼ�߶���0
    	int pre = 0;//ǰһ����ߵĸ߶ȣ�Ϊ���ҳ������ұ߽�ʱ�Ĺյ�
    	int cur = 0;//��ǰ��ߵĸ߶ȣ�Ϊ��ȷ���¼���ĸ߶��ǲ��ǹյ�
    	for (int i = 0; i < b.size(); i ++)
    	{
    		if (b[i].second < 0)
    			height.insert(-b[i].second);//������߽�Ҫ���뵽�߶�set�У��ж��Ƿ��ǹյ�
    		else
    			height.erase(height.find(b[i].second));//�����ұ߽�Ҫ�Ӹ߶��е��������жϵ�����͵���ǰ�߶��Ƿ����仯
    		cur = *height.rbegin();//ȡ�����ĸ߶�
    		if (pre != cur)//������ߵ����߶�ǰ�����߶ȷ����仯��˵������߶��ǹյ�
    		{
    			r.push_back({b[i].first,cur});
    			//�������߽磬˵��������һ����ߵĸ߶ȵ���߽磬���Թյ�ĸ߶Ⱦ��������ߵĸ߶�
    			//������ұ߽磬˵��������һ����ߵĸ߶ȵ��ұ߽磬�յ�ĸ߶Ȳ��������ߵ㣬���ǵ�������ߵĸ߶�cur
    			pre = cur;
    		}
    	}
    	return r;
    }
};
