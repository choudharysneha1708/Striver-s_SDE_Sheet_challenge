//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int MaxSum(int  arr[], int ver, vector<int>& dp){
        
        if(ver==0)return arr[0];
        if(ver<0)return 0;
        if(dp[ver]!=-1)return dp[ver];
        int pick=arr[ver]+MaxSum(arr,ver-2, dp);
        
        int notPick=MaxSum(arr, ver-1, dp);
        return dp[ver]=max(pick, notPick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return MaxSum(arr, n-1, dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends