#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	//���ȸ����ö�Ӧ��ϵ�ȽϺ�...
    	//ֻ���������֣�* #���ÿ�����
    	//0���ؿո� 1���ؿ� �������ַ�����Ӧ��ĸ
    	vector<string> result;
    	string mapping[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    	//�Ȱѵ�һ�����ֶ�Ӧ����ĸ��ʼ��������� �޷�����ѭ��
    	if (digits.size() > 0){
    		string temp = mapping[digits[0]-'0'];
    		for (int i = 0; i<temp.length(); i++){
    			//cout<<"temp[i]:"<<temp[i]<<endl;
    			string t = "";
    			t += temp[i];//��charת����stringҪע������
    			result.push_back(t);
    		}
    	}
    	for (int i= 0; i < result.size(); i++)
    		cout<<result[i]<<endl;
    	for (int i = 1; i <digits.size(); i++){
    		string temp1 = mapping[digits[i]-'0'];
    		cout<<"temp1 "<<temp1<<endl;
    		vector<string> temp2;
    		for (int m = 0; m < temp1.length(); m++){
    			cout<<"temp[m]:"<<temp1[m]<<endl;
    			for (int n = 0; n < result.size(); n++){
    				cout<<"result[n]:"<<result[n]<<endl;
    				temp2.push_back(temp1[m]+result[n]);
    			}
    		}
    		result = temp2;
    	}
    	return result;
    }
};
/**int main(){
	Solution s;
	string digits = "23";
	vector<string> result = s.letterCombinations(digits);
	for (int i = 0; i < result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}
**/
