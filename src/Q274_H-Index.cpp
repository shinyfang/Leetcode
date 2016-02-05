#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int h = 0;
    	sort(citations.rbegin(),citations.rend());
    	for (int i = 0; i < citations.size(); i ++)
    	{
    		if (citations[i] > i + 1)
    			h = i + 1;
    		else if (citations[i] == i + 1)
    			return citations[i];
    	}
    	return h;
    }
};
