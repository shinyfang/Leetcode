#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
    	//�ݹ�ᳬʱ����������������������������������������
    	//���˶��ٱ��ˣ�������̫������~~~~(>_<)~~~~
    	bool flag = false; //���֮ǰ�Ƿ�������*
    	int pre1;
    	int pre2; //���֮ǰƥ��*��s pλ��
    	int p1 = 0;
    	int p2 = 0; //��¼s p�Ƚϵ�λ��
    	while (p1 < s.length())
    	{
    		if (p2 == p.length() || (s[p1] != p[p2] && p[p2] != '*' && p[p2] != '?'))
    		{
    			if (flag)
    			{
    				//ΪʲôҪ��flag����Ϊƥ��*ʱ�����ܳ��ֵ�p1��*+1ƥ�����ˣ�����ʵ����Ӧ����p1�����ĳ���Կ���ƥ�����ҳɹ�
    				p1 = pre1 + 1;
    				p2 = pre2 - 1;
    			}
    			else
    				return false;
    		}
    		else if (s[p1] == p[p2] || p[p2] == '?')
    		{
    			p1++;p2++;
    		}
    		else if (p[p2] == '*')
    		{
    			flag = true;
    			while (p2 < p.length() && p[p2] == '*')
    				p2++;
    			if (p2 == p.length()) //pȫ����*������ȫƥ��s��ֱ�ӷ���true
    				return true;
    			while (p1 < s.length() && s[p1] != p[p2] && p[p2] != '?')//�����ס���ܺ�?ƥ��
    				p1++;
    			if (p1 == s.length()) //�����ƥ�䲻�ϣ�ֱ�ӷ���false
    				return false;
    			else
    			{//���ص�Ӧ��������ƥ���ϵĲ��֣����������ƶ�
    				pre1 = p1;pre2 = p2;
    			}
    		}
    	}
    	while (p[p2] == '*' && p2 < p.length())
    		p2++;
    	if (p2 == p.length())
    		return true;
    	return false;
    }
};
/**int main(){
	string s = "c";
	string p = "*?*";
	Solution t;
	cout<<t.isMatch(s,p);
	return 0;
}
**/
