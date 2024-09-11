#include<iostream>
#include<vector>
#include<numeric> 

using namespace std;


bool f(int index,int target,vector<int>&arr , vector<vector<int> > &dp) {
        if(target == 0){
            return true;
        }
        if(index == 0){
            return arr[0] == target;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool not_take = f(index-1 , target ,arr,dp);
        bool take = false;
        if(arr[index]<=target){
            take = f(index-1 , target-arr[index],arr,dp);
        }

        return dp[index][target] = take||not_take;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    
    
    int s = accumulate(arr.begin(),arr.end(),0);

    if(s%2 != 0){
        cout<< "False";
        return 0;
    }
    vector<vector<int> > dp (n , vector<int>(s/2 + 1,-1));
    int ans = f(n-1,s/2 ,arr ,dp);
    
    if(ans == 1){
        cout<< "True";
    }
    else{
        cout<< "False";
    }

}

// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)

// This problem is same as subset sum problem. only differece is that we have to check if the sum of the array is even or not. If it is odd then we can't divide the array into two equal parts. If it is even then we can divide the array into two equal parts and check if the sum of the two parts is equal to the sum of the array or not. If it is equal then we can say that the array can be divided into two equal parts.

// so here target = sum/2