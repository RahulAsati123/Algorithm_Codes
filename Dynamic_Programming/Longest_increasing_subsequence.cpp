#include<iostream>
#include<vector>
using namespace std;

int f(int index , int prev , vector<int> &nums,vector<vector<int> > &dp){
      
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }

        int not_take = 0+f(index+1 , prev ,nums,dp);
        int take = -1e9;
        if(prev == -1 || nums[index]>nums[prev]){
            take =  1+f(index+1, index ,nums,dp);
        }
        return dp[index][prev+1] = max(not_take, take);
    }

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int x; 
        cin>>x;
        nums.push_back(x);
    }
    vector<vector<int> > dp(n,vector<int>(n+1,-1));
    int ans = f(0,-1,nums,dp);
    cout<<ans;

}


// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// * Define base case that is when index == nums.size() return 0 because it means we have reached the end of the array.
// * take two cases one is when we take the element and other is when we don't take the element.
// * if the element is greater than the previous element then only we can take the element.
// * return the maximum of taking the element or not taking the element.
// * Use memoization to store the result of subproblems to avoid recomputation of same subproblems.
// * Return the maximum length of increasing subsequence.