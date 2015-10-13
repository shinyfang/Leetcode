#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	if (n == 0)
    		return result;
    	//二叉树的实现用递归
    	result = generate(1,0,n,"(",result);//初始化首字母必为（
    	return result;
    }
    vector<string> generate(int l, int r, int n, string s,vector<string> &result){
    	if (l == n && r == n){
    		cout<<"l=r=n s:"<<s<<endl;
    		result.push_back(s);
    	}
    	else if (l == n && l > r){
    		//cout<<"l==n l:"<<l<<" r:"<<r<<" s:"<<s<<endl;
    		generate(l,r+1,n,s+")",result);
    	}
    	else if (l > r){
    		//cout<<"l<r l:"<<l<<" r:"<<r<<" s:"<<s<<endl;
    		generate(l+1,r,n,s+"(",result);
    		generate(l,r+1,n,s+")",result);
    	}
    	else{//l == r情况
    		//cout<<"l==r ="<<l<<" s:"<<s<<endl;
    		generate(l+1,r,n,s+"(",result);
    	}
    	return result;
    }
};
/**int main(){
	Solution s;
	int n = 3;
	vector<string> result = s.generateParenthesis(n);
	for (int i = 0; i < result.size(); i++){
		string temp = result[i];
		for (int j = 0; j < temp.length(); j++){
			cout<<temp[j];
		}
		cout<<endl;
	}
	return 0;
}
**/
