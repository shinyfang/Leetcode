#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
//֧�ֿ��ٲ���set multiset ����ɾ�����Ҷ���lognʱ������� ����Ԫ�ض��Ǵ�С��������õ�
//Ȧ��k��Χ�ڵ�����ÿ���¼���һ����ʱ�����Ƿ��з��ϲ�ֵΪt�����
//���ǵ������������븺��֮������ᳬ�����ֵ���� long long�洢
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (nums.size() < 2 || k == 0 || t < 0)
    		return false;
    	multiset<long long> m;
    	for (int i = 0; i < nums.size(); i ++)
    	{
    		if (m.size() > k)//������k����ʱ����k�������ǿ������i����ƥ�����������ֻ�ܴ���kʱ�ŵ�����һ����
    			m.erase(m.find(nums[i-k-1]));
    		//�����Ƚϵ�ǰ����
    		multiset<long long>::iterator it = m.lower_bound(nums[i]);//lower_bound���ش��ڵ���������ĵ�һ��Ԫ�ص�λ��
    		if (it != m.end() && abs(*it - nums[i]) <= t)
    			return true;
    		it = m.upper_bound(nums[i]);//���ش���������ĵ�һ��Ԫ�ص�λ�ã�����ʱ����Ҫ�ҵ���С������ǵĵ�һ��Ԫ�ص�λ��
    		if (it != m.begin() && abs(*(--it) - nums[i]) <= t)
    			return true;
    		m.insert(nums[i]);
    	}
    	return false;
    }
};
