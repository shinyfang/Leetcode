#include<iostream>
#include<cstring>
/**
 * 大数问题
 */
using namespace std;
class Solution {
public:
	void Print1ToMaxOfN (int n)
	{
		if (n <= 0)
			return;
		char* result = new char[n+1];
		memset(result,0,sizeof(result));
		for (int i = 0; i < 10; i++)
		{
			result[0] = '0' + i;
			Print1ToMaxOfNRecursively(result,n,0);
		}
		delete [] result;
	}
	void Print1ToMaxOfNRecursively(char* result, int n, int index)//index处已经写入了
	{
		if (index == n - 1)
		{
			Print(result);
			return;
		}
		for (int i = 0; i < 10; i++)
		{
			result[index+1] = '0' + i;
			Print1ToMaxOfNRecursively(result,n,index+1);
		}
	}
	void Print(char* result)
	{
		int i = 0;
		while (result[i] == '0')
			i++;
		while (i < strlen(result))
		{
			cout<<result[i]<<" ";
			i++;
		}
		cout<<endl;
	}
};
/**int main(){
	int n = 3;
	Solution s;
	s.Print1ToMaxOfN(n);
	return 0;
}
**/
