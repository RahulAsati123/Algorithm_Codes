#include<iostream>
#include<vector>
using namespace std;

int f(int i , int j , vector<int> arr , vector<vector<int> > &dp){
    if(i == j){                         // -----------> base condition
        return 0;
    }

    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    int mini = 1e9;
    for(int k = i ; k<j ; k++){
        int steps = f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j];        // ---------> result given by kth partition
        if(steps < mini){
            mini= steps;
        }
    }
    return dp[i][j] = mini;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    vector<vector<int> > dp(n,vector<int>(n , -1));

    cout<<f(1,n-1,arr,dp);


}


// Time Complexity: O(n^3)
// Space Complexity: O(n^2)



// * Define base case that is when i == j return 0 because it means the partition contains only one matrix.
// * take kth element in between and divide the problem in two parts. i.e. f(i,k) and f(k+1,j) and add the cost of multiplication of two matrices.
// * return the minimum cost of multiplication of two matrices.
// * Use memoization to store the result of subproblems to avoid recomputation of same subproblems.

// Youtube : https://www.youtube.com/watch?v=vRVfmbCFW7Y
