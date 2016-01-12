#include<iostream>
#include<vector>
using namespace std;
//������˹����ɸ�����������ķ���
class Solution {
public:
    int countPrimes(int n) {
    	if (n <= 2)//С��n������
    		return 0;
    	vector<bool> f(n-1,true);//С��n��������n
    	f[0] = false;
    	for (int i = 2; i*i < n; i++)
    	{
    		if (f[i-1] == false)
    			continue;
    		for (int j = i*i; j < n; j+=i)//i�ı����൱����iΪ����ĵȲ����У�����Ҫ��i^2���жϣ���Ϊi������
    			f[j-1] = false;
    	}
    	int r = 0;
    	for (int i = 0; i < f.size(); i++)
    		r += f[i]==true?1:0;
    	return r;
    }
};
