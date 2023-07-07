//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
ll mod = 1e9+7;
class Solution {
    
  public:
    int countPartitions(int N, int d, vector<int>& arr) {
        // Code here
        ll sum=0;
        for(auto e: arr)sum+=e;
        sum+=d;
        if(sum%2)return 0;
        sum/=2;
        vector<vector<ll>>dp(N+1, vector<ll>(sum+1,0));
        for(int i=0; i<=N; ++i)dp[i][0]=1;
        for(int i=1; i<=N; ++i){
            for(int j=0; j<=sum; ++j){
                if(j>=arr[i-1]){
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%mod;
                }else{
                    dp[i][j]=(dp[i-1][j])%mod;
                }
            }
        }
        return (dp[N][sum])%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends