#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int sum = nums1.size() + nums2.size();
    	if (sum%2 == 0)//��ż����
    		return (find_median(nums1,0,nums2,0,sum/2-1)+
    				find_median(nums1,0,nums2,0,sum/2))/2.0;
    	else
    		return find_median(nums1,0,nums2,0,sum/2);
  }
    double find_median(vector<int>& n1, int s1, vector<int>& n2, int s2, int target){
    	if (n1.size() - s1 > n2.size() -s2)//�ѽ϶̵��������ǰ��
    		return find_median(n2,s2,n1,s1,target);
    	if (s1 == (int)n1.size())//���n1������Ч������Ϊ0��˵��s1�Ѿ���������index
    		return n2[target+s2];//��ôֱ�ӷ���n2�����index=target����
    	if (target == 0)//���Ҫ���ص�һС������ֱ�ӱȽ�n1 n2���λ��index=0���������ؽ�С��
    		return n1[s1]<n2[s2]?n1[s1]:n2[s2];
    	int m1 = target/2>(n1.size()-1-s1)?(n1.size()-1):(target/2+s1);
    	//m1��ָ��target�԰뻮�֣�n1����Ӧ�ñȽϵ�����index
    	int m2 = target-(m1-s1)-1+s2;
    	//m2��n2����Ӧ�ñȽϵ�����index
    	if (n1[m1] == n2[m2])
    		return n1[m1];
    	else if (n1[m1] < n2[m2])
    		return find_median(n1,m1+1,n2,s2,target+s1-m1-1);
    	//���һ�������ǣ��Ѿ�ȷ����target+1�е��ļ�������ʣ����Ҫ�õ���index=target����
    	else
    		return find_median(n1,s1,n2,m2+1,target+s2-m2-1);
    }
};
/**int main(){
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(4);
	nums1.push_back(6);
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(5);
	nums2.push_back(6);
	Solution s;
	double out = s.findMedianSortedArrays(nums1,nums2);
	//double out = s.find_median(nums1,0,nums2,0,2);
	cout<<out<<endl;
	return 0;
}
**/
