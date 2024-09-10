#include<iostream>
#include<vector>
using namespace std;

int knapsack(int index , int w , vector<int> &values , vector<int> &weights , vector<vector<int> >&dp){

    if(index == 0){
        if(weights[index] <= w){
            return values[index];
        }
        else{
            return 0;
        }
    }
    if(dp[index][w] != -1){
        return dp[index][w];
    }

    int not_take = knapsack(index-1 , w , values , weights,dp);
    int take = -999999;
    if(weights[index]<=w){
        take = values[index]+knapsack(index-1 , w-weights[index] , values , weights,dp);
    }
    return dp[index][w] = max(take , not_take);

}

int main(){
    int n;
    int w;
    

    vector<int> weights;
    vector<int> values;
   
    
    cin>>n;
    cin>>w;

  
    

    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        weights.push_back(input);
    }
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        values.push_back(input);
    }
   
 
    vector<vector<int> > dp(n,vector<int>(w+1,-1));

    
    int ans = knapsack(n-1 , w , values , weights, dp);
    cout<<ans;



}





// Explanation: https://www.youtube.com/watch?v=GqOmJHQZivw&t=27s


// Write down the recursive functions for take and not take.
// Define base condition for index == 0. 
// Define main and call function and store that in ans and give condition to return the answer.
// Now for memoization define a 2-D vector dp with n rows and max_weight+1 columns having default value of all the entries as -1.
// Now give condition in the function storing the max(take , not_take) in dp while returning.
// Now before calling not_take , check if the dp[index][amount]!=-1 if it is true return dp[index][amount].
// Now call the function in main and print the ans.

// Time complexity : O(n*w)
// Space complexity : O(n*w)