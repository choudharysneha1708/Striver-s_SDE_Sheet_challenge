//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int maxProfit(int index, int capacity, int val[], int wt[], vector<vector<int>>&dp){
        if(index<0 || capacity ==0)return 0;
        if(index == 0 && capacity<wt[index])return 0;
        if(dp[index][capacity]!=-1)return dp[index][capacity];
        int take =0;
        int NotTake = maxProfit(index -1, capacity, val, wt, dp);
        if(capacity>= wt[index]){
            take =val[index]+ maxProfit(index, capacity-wt[index], val, wt, dp);
        }
        return dp[index][capacity]= max(take, NotTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return maxProfit(N-1,W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends