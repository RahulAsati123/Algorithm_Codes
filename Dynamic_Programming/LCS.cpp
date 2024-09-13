#include<iostream>
#include<string>
#include<vector>
using namespace std; 

int f(int index1 ,int index2 ,string &s,string &t, vector<vector<int> > &dp){
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



// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// * Define base case that is when index1 < 0 or index2 < 0 return 0 because it means the string is empty.
//  there the is the condition if both the characters are same then return 1 + f(index1-1,index2-1,s,t,dp) because we have found a common character.
//  else return max(f(index1-1,index2,s,t,dp) , f(index1,index2-1,s,t,dp)) because we have to find the maximum length of common subsequence.
// * Use memoization to store the result of subproblems to avoid recomputation of same subproblems.
// * Return the length of longest common subsequence.
