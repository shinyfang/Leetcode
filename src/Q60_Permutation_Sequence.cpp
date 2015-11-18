#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		string result;
		vector<int> temp;
		for (int i = 0; i < n; i++)
			temp.push_back(i + 1);
		int exc = 0;
		int start = 0;
		int max = 1;
		int temp2 = n;
		int temp3 = n;
		while (--temp2)
			max *= temp2;
		while (k > 1)
		{
			int exc = get(temp, temp3, k, max, start);
			k -= max*exc;
			start++;
			max /= (temp3-1);
			temp3--;
		}
		for (int i = 0; i < n; i++)
			result[i] = temp[i]+'0';
		return result;
	}
	int get(vector<int> &result, int n, int k, int max, int start)
	{
		cout<<"n="<<n<<" k="<<k<<" max="<<max<<" start="<<start<<endl;
		int exc = 0;
		for (int i = 1; i < n; i++)
		{
			if (i * max < k && (i + 1) * max >= k)
			{
				exc = i;
				break;
			}
		}
		permutation(result, start, start+exc);
		return exc;
	}
	vector<int> permutation(vector<int> &result, int p1, int p2)
	{
		swap(result[p1], result[p2]);
		sort(result.begin() + p1 + 1, result.end());
		return result;
	}
};
/**int main() {
	int n = 2;
	int k = 1;
	Solution s;
	string result = s.getPermutation(n, k);
	for (int i = 0; i < n; i++)
		cout<<result[i];
	return 0;
}
**/
