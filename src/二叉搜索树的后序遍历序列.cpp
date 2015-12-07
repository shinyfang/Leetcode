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
			if (sequence[right] <= root)//������Ӧ�ö�����root������ֱ�ӷ���false
				return false;
		}
		bool l = true;
		cout<<sequence[left]<<" "<<sequence[right]<<endl;
		if (left > 0 && left < length - 1)//����������Ҫ����һ�����еñȽ�
			l = VerifySequenceOfBST(sequence,left);
		if (left > 0 && left == length - 1)//˵��root���ȫ��������
			l = VerifySequenceOfBST(sequence,left-1);

		bool r = true;
		if (left < length - 1)//��֤��������
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
