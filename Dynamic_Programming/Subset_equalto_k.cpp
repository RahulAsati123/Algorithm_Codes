#include<iostream>
#include<vector>
using namespace std;


bool f(int index , int target , vector<int>arr , vector<vector<int> > &dp){
    if(target == 0){
        return true;
    }
    if(index == 0 ){
        return arr[0] == target;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool not_take = f(index-1 , target , arr,dp);
    bool take = false;
    if(arr[index]<=target){
        take = f(index-1 , target-arr[index] ,arr,dp);
    }
    return dp[index][target] = take || not_take;

}


int main(){
    int n;
    int target; 
    cin>>n;
    cin>>target;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    
    vector<vector<int> > dp (n , vector<int>(target+1,-1));
    int ans = f(n-1,target ,arr ,dp);
    
    if(ans == 1){
        cout<< "True";
    }
    else{
        cout<< "False";
    }

}


// Time Complexity: O(n*target)
// Space Complexity: O(n*target)

// * Define base case that is when target == 0 return true because it means the subset is found.
// if we reach index  == 0 and  arr[index] == target then return true.
// * take two cases one is when we take the element and other is when we don't take the element.
// * if the element is less than target then only we can take the element.
// * return the result of taking the element or not taking the element.
// * Use memoization to store the result of subproblems to avoid recomputation of same subproblems.