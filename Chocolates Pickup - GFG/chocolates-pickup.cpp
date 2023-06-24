//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n,m;
    bool check(int x, int y){
        if(x<0 || y<0 || x>=n || y>=m)return 0;
        return 1;
    }
    int dfs(int x, int y1, int y2, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
        if(x==n-1 && y1 != y2)return dp[x][y1][y2]= grid[x][y1]+grid[x][y2];
        if(x==n-1 && y1 == y2)return dp[x][y1][y2]= grid[x][y1];
        if(dp[x][y1][y2]!=-1)return dp[x][y1][y2];
        int maxi=0;
        for(int j1=-1 ; j1<=1; ++j1){
            for(int j2=-1 ; j2<=1; ++j2){
                if(check(x+1 , y1+j1) && check(x+1,y2+j2) ){
                    maxi=max(maxi, dfs(x+1 ,y1+ j1,y2+j2, grid,dp));
                }
            }
        }
        if(y1!=y2) maxi+=grid[x][y2];
        return dp[x][y1][y2]= maxi+grid[x][y1] ;
    }
    int solve(int N, int M, vector<vector<int>>& grid) {
        n=N;
        m=M;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
        return dfs(0,0,m-1, grid, dp);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends