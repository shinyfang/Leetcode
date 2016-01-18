#include<iostream>
using namespace std;
class Solution {
public:
	//求的是面积的总和
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int repet = 0;//把重复的减掉
    	if (A == C || B == D || E == G || F == H || C <= E || G <= A || D <= F || H <= B)
    		repet = 0;
    	else
    	{
			int x1 = E <= A ? A : E;
			int x2 = G < C ? G : C;
			int y1 = H >= D ? D : H;
			int y2 = F > B ? F : B;
			repet = (x2 - x1)*(y1 - y2);
    	}
    	return (C-A)*(D-B)+(G-E)*(H-F)-repet;
    }
};
