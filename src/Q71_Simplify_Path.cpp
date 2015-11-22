#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
    	string result;
    	for (int i = 0; i < path.length(); i++)
    	{
    		if (result.length() == 0) //���Ϊ�գ����ȥ
    			result += path[i];
    		else if (result[result.length()-1] == '/' && path[i] == '/') //���path��ǰΪ/������result���һλ���ʲô
    			continue;
    		else if (result[result.length()-1] != '/' && path[i] == '/')
    			result += path[i];
    		else if (path[i] == '.') //���path��ǰΪ.������֮��������
    		{
    			if (i+1 == path.length() || path[i+1] == '/') // ./�����Դ�ʱ�ĵ�
    				continue;
    			else if (path[i+1] != '/' && path[i+1] != '.') // .fshfs��ʱ�㵱���ļ�������һ����
    				result += path[i];
    			else if (path[i+1] =='.')
    			{
    				if (i+2 == path.length() || path[i+2] == '/') //  ../��������һ��
    				{
    					if (result.length() > 1) //������һ��
    					{
    						if (result[result.length()-1] == '/')
    							result.erase(result.end()-1);
    						while (result[result.length()-1] != '/')
    							result.erase(result.end()-1);
    					}
    				}
    				else
    				{
    					while (i < path.length() && path[i] != '/') // ..fhsiuaf�����ļ�������һ����
    					{
    						result += path[i];
    						i++;
    					}
    					i--; //ע��Ҫ��һλ��
    				}
    			}
    		}
    		else
    			result += path[i];
    	}
    	if (result.length() > 1 && result[result.length()-1] == '/')
    		result.erase(result.end()-1);
    	return result;
    }
};
/**int main()
{
	string path = "/..aa/...hidden/";
	Solution s;
	string result = s.simplifyPath(path);
	for (int i = 0; i < result.length(); i++)
		cout<<result[i];
	return 0;
}
**/
