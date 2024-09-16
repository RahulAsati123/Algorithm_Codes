#include<iostream>
#include<vector>
#include <climits>

using namespace std;


int coin_change(int index , int sum , vector<int> &coins , vector<vector<int> > &dp){
    if(index ==0 ){
        if(sum%coins[index] == 0){
            return sum/coins[index];
        }
        else{
            return 1e9;
        }
    }
    if(dp[index][sum] != -1){
        return dp[index][sum];
    }

    int not_take = coin_change(index-1 , sum , coins,dp);
    int take = INT_MAX;
    if(coins[index] <= sum){
        take = 1 + coin_change(index,sum-coins[index],coins,dp);
    }

    return dp[index][sum] = min(take,not_take);
    }


int main(){

    int n;
    int sum;
    vector<int> coins;
    cin>>n;
    cin>>sum;

    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        coins.push_back(input);
    }
   

    vector<vector<int> > dp(n,vector<int>(sum+1,-1));    
    int ans = coin_change(n-1,sum,coins,dp);
   
    if(ans>1e9){
        cout<< -1;
    }
    cout<<ans;

}








// Explanation : https://www.youtube.com/watch?v=myPeWb3Y68A

// Write down the recursive functions for take and not take.
// Define base condition for index == 0.
// Define main and call function and store that in ans and give condition to return the answer.
// Now for memoization define a 2-D vector dp with n rows and amount+1 columns having default value of all the entries as -1.
// Now give condition in the function storing the min(take , not_take) in dp while returning.
// Now before calling not_take , check if the dp[index][amount]!=-1 if it is true return dp[index][amount].

// space complexity : O(n*sum)
// time complexity : O(n*sum)