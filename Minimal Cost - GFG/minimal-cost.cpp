//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int calculate(vector<int>& height, int ver, int k, vector<int>& dp){
        if(ver==0)return 0;
        if(dp[ver]!=-1)return dp[ver];
        int x=INT_MAX;
        for(int i=1; i<=k; ++i){
            if(ver-i>=0){
                int y=calculate(height, ver-i, k ,dp) +abs(height[ver]-height[ver-i]);
                x=min(x,y);
            }
        }
        return dp[ver]=x;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return calculate(height, n-1, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends