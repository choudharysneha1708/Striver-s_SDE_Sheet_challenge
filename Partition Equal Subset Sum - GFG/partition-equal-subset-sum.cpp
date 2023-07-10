//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(int index, int target, vector<vector<int>>&dp, int arr[]){
        if(target==0)return dp[index][target]=  1;
        if(index==0)return dp[index][target]= (arr[index]==target);
        if(dp[index][target]!=-1)return dp[index][target];
        bool take =false;
        bool nottake=check(index-1, target, dp, arr);
        if(arr[index-1]<=target)take= check(index-1, target-arr[index-1], dp, arr);
        return dp[index][target]= (take| nottake);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; ++i){
            sum+=arr[i];
        }
        if(sum%2)return 0;
        sum/=2;
        vector<vector<int>>dp(N, vector<int>(sum+1, -1));
        return  check(N-1, sum, dp, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends