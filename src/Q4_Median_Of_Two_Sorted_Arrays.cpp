#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int sum = nums1.size() + nums2.size();
    	if (sum%2 == 0)//奇偶讨论
    		return (find_median(nums1,0,nums2,0,sum/2-1)+
    				find_median(nums1,0,nums2,0,sum/2))/2.0;
    	else
    		return find_median(nums1,0,nums2,0,sum/2);
  }
    double find_median(vector<int>& n1, int s1, vector<int>& n2, int s2, int target){
    	if (n1.size() - s1 > n2.size() -s2)//把较短的数组放在前面
    		return find_median(n2,s2,n1,s1,target);
    	if (s1 == (int)n1.size())//如果n1数组有效的数字为0，说明s1已经超过最大的index
    		return n2[target+s2];//那么直接返回n2的相对index=target即可
    	if (target == 0)//如果要返回第一小的数，直接比较n1 n2相对位置index=0的数，返回较小者
    		return n1[s1]<n2[s2]?n1[s1]:n2[s2];
    	int m1 = target/2>(n1.size()-1-s1)?(n1.size()-1):(target/2+s1);
    	//m1是指将target对半划分，n1数组应该比较的数的index
    	int m2 = target-(m1-s1)-1+s2;
    	//m2是n2数组应该比较的数的index
    	if (n1[m1] == n2[m2])
    		return n1[m1];
    	else if (n1[m1] < n2[m2])
    		return find_median(n1,m1+1,n2,s2,target+s1-m1-1);
    	//最后一个参数是，已经确定了target+1中的哪几个数，剩下需要得到的index=target的数
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
