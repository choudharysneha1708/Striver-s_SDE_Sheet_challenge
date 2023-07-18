//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int MaxSum(int arr[], vector<int>&dp, int index){
	    if(index == 0)return dp[index] = arr[0];
	    if(index<0)return 0;
	    if(dp[index] != -1)return dp[index];
	    int Pick = arr[index] + MaxSum(arr, dp,index - 2);
	    int NotPick = MaxSum(arr, dp, index - 1);
	    return dp[index] = max(Pick, NotPick);
	}
	int findMaxSum(int *arr, int n) {
        vector<int>dp(n, -1);
        return MaxSum(arr, dp, n-1);
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