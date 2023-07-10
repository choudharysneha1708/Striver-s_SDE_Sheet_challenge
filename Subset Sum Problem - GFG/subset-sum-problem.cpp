//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(int index, int target,vector<int>&arr, vector<vector<int>>&dp){
        if(target==0)return dp[index][target]= 1;
        if(index==0)return dp[index][target]= (target== arr[index]);
        if(dp[index][target]!=-1)return dp[index][target];
        bool take=false;
        bool nottake=check(index-1, target, arr,dp);
        if(arr[index]<=target){
            take=check(index-1, target- arr[index], arr, dp);
        }
        return dp[index][target]=(take|| nottake);
    }
    bool isSubsetSum(vector<int>arr, int target){
            //as there is 2 state of dp so we need to make 2d dp array to memorize this recursion
            int n= arr.size();
            vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
            return check(n-1, target, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends