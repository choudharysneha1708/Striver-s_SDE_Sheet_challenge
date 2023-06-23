//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int m,n;
     int mod= 1e9+7;
    bool check(int x, int y){
        if(x<0 || y<0 || x>=m || y>=n)return 0;
        return 1; 
    }
    long long dfs (int x, int y,vector<vector<int>>& ob, vector<vector<long long>>&dp ){
        if(x==m-1 && y==n-1)return dp[x][y]=1;
        if(dp[x][y]!=-1)return dp[x][y];
        long long noOfPath=0;
        if(check(x+1, y) && ob[x+1][y]==0)noOfPath+=(dfs(x+1,y,ob, dp)%mod);
        if(check(x,y+1) &&  ob[x][y+1]==0)noOfPath+=(dfs(x,y+1,ob, dp)%mod);
        return dp[x][y]=(noOfPath)%mod;

    }
    int totalWays(int N, int M, vector<vector<int>>& ob) {
        // Code here
         m=N;
        n=M;
        vector<vector<long long>>dp(m, vector<long long>(n,-1));
        if(ob[0][0]==1)return 0;
        return (dfs(0,0,ob, dp)%mod); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends