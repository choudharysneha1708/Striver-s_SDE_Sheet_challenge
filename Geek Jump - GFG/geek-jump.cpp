//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findEnergy(vector<int>& height, int ver, vector<int>&dp){
        if(ver==0)return dp[ver]=0;
        if(dp[ver]!=-1)return dp[ver];
        int oneStep=findEnergy(height,ver-1,dp)+ abs(height[ver]- height[ver-1]);
        int twoStep=INT_MAX;
        if(ver>1)
        twoStep=findEnergy(height,ver-2, dp)+abs(height[ver]- height[ver-2]);
        return dp[ver]= min(oneStep, twoStep);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return findEnergy(height, n-1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends