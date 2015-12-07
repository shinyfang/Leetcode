#include<iostream>
using namespace std;
class Solution{
public:
	bool VerifySequenceOfBST(int sequence[], int length)
	{
		if (sequence == NULL || length <= 0)
			return false;
		int root = sequence[length-1];
		int left = 0;
		for (; left < length-1; left++)
		{
			if (sequence[left] >= root)
				break;
		}
		int right = left;
		for (; right < length-1; right++)
		{
			if (sequence[right] <= root)//右子树应该都大于root，否则直接返回false
				return false;
		}
		bool l = true;
		cout<<sequence[left]<<" "<<sequence[right]<<endl;
		if (left > 0 && left < length - 1)//左子树至少要大于一个才有得比较
			l = VerifySequenceOfBST(sequence,left);
		if (left > 0 && left == length - 1)//说明root左边全是左子树
			l = VerifySequenceOfBST(sequence,left-1);

		bool r = true;
		if (left < length - 1)//保证有右子树
			r = VerifySequenceOfBST(sequence+left,length-left-1);
		return (l&&r);
	}
};
/**int main(){
	int sequence[7] = {5,7,6,9,11,10,8};
	int length = 7;
	Solution s;
	cout<<s.VerifySequenceOfBST(sequence,length);
	return 0;
}
**/
