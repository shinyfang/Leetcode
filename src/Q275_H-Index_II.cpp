#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int h = 0;
    	int p1 = 0;
    	int p2 = citations.size()-1;
    	while (p1 <= p2)
    	{
    		int mid = (p1 + p2) / 2;
    		if (citations[mid] >= citations.size() - mid)
    		{
    			h = citations.size() - mid;
    			p2 = mid - 1;
    		}
    		else
    			p1 = mid + 1;
    	}
    	return h;
    }
};
