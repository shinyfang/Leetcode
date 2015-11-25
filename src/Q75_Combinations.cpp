#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		if (k == 0 || n == 0 || n < k)
			return result;
		if (k > 1) {
			k--;
			n--;
			//cout << "n=" << n << " k=" << k << endl;
			result = combine(n, k);
			//cout << "over!" << endl;
			vector<vector<int> > temp1;
			for (int i = 0; i < result.size(); i++) {
				for (int j = result[i][result[i].size() - 1] + 1; j <= n+1; j++) {//注意这里，在k--和n--递归完之后，要恢复n，使得k长度能正常写入
					vector<int> temp2 = result[i];
					temp2.push_back(j);
					temp1.push_back(temp2);
				}
			}
			result.clear();
			result = temp1;
		} else {
			// k == 1
			//cout << "k====" << k << " n====" << n << endl;
			for (int i = 1; i <= n; i++) {
				vector<int> temp;
				temp.push_back(i);
				result.push_back(temp);
			}
		}
		return result;
	}
};
/**int main() {
	int n = 4;
	int k = 3;
	Solution s;
	vector<vector<int> > result = s.combine(n, k);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
**/
