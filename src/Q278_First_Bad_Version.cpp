#include<iostream>
using namespace std;
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
    	int min = 0;
    	int p1 = 1;
    	int p2 = n;
    	while (p1 <= p2)
    	{
    		int mid = p1 + (p2 - p1) / 2;//·ÀÖ¹Òç³ö
    		if (isBadVersion(mid))
    		{
    			min = mid;
    			p2 = mid - 1;
    		}
    		else
    			p1 = mid + 1;
    	}
    	return min;
    }
};
