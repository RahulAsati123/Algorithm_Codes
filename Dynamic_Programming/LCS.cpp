#include<iostream>
#include<string>
#include<vector>
using namespace std; 

int f(int index1 ,int index2 ,string s,string t, vector<vector<int> > &dp){
	if(index1 < 0 || index2 <0){
		return 0;
	}
	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}
	if(s[index1] == t[index2]){
		return 1+f(index1-1 ,index2-1,s,t,dp);
	}

	return dp[index1][index2] = max(f(index1-1,index2, s, t,dp) , f(index1 , index2-1,s,t,dp));
}
int main(){
    string s,t;
    cin>>s>>t;
    int n1 = s.size();
	int n2 = t.size();
	vector<vector<int> > dp(n1,vector<int>(n2,-1));
	int ans = f(n1-1,n2-1,s,t,dp);
    cout<<ans;
	
}