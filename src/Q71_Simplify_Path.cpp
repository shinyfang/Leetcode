#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
    	string result;
    	for (int i = 0; i < path.length(); i++)
    	{
    		if (result.length() == 0) //如果为空，存进去
    			result += path[i];
    		else if (result[result.length()-1] == '/' && path[i] == '/') //如果path当前为/，讨论result最后一位存的什么
    			continue;
    		else if (result[result.length()-1] != '/' && path[i] == '/')
    			result += path[i];
    		else if (path[i] == '.') //如果path当前为.，讨论之后各种情况
    		{
    			if (i+1 == path.length() || path[i+1] == '/') // ./，忽略此时的点
    				continue;
    			else if (path[i+1] != '/' && path[i+1] != '.') // .fshfs此时点当做文件夹名的一部分
    				result += path[i];
    			else if (path[i+1] =='.')
    			{
    				if (i+2 == path.length() || path[i+2] == '/') //  ../返回是上一层
    				{
    					if (result.length() > 1) //返回上一层
    					{
    						if (result[result.length()-1] == '/')
    							result.erase(result.end()-1);
    						while (result[result.length()-1] != '/')
    							result.erase(result.end()-1);
    					}
    				}
    				else
    				{
    					while (i < path.length() && path[i] != '/') // ..fhsiuaf当做文件夹名的一部分
    					{
    						result += path[i];
    						i++;
    					}
    					i--; //注意要回一位数
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
