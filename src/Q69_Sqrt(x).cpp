#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
    	//¶þ·Ö
    	if (x == 0 || x == 1)
    		return x;
    	int begin = 1;
    	int end = (x/2)+1;
    	while (begin <= end)
    	{
    		int mid = (begin+end)/2;
    		if (x/mid >= mid && x/(mid+1)<(mid+1)) //mid^2<=x<(mid+1)^2,reurn mid
    			return mid;
    		else if (x/mid < mid)
    			end = mid-1;
    		else
    			begin = mid+1;
    	}
    	return -1;
    }
};
/**int main(){
	int x = 2147395600;
	Solution s;
	cout<<s.mySqrt(x);
	return 0;
}
**/
