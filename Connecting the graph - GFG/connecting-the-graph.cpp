//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<bool>vis;
    vector<vector<int>>adj;
    private:
        void dfs(int ver){
            vis[ver]=1;
            for(auto child: adj[ver]){
                if(!vis[child]){
                    dfs(child);
                }
            }
        }
    private:
        void fillAdj(vector<vector<int>>& edge){
            for(auto e: edge){
                adj[e[0]].push_back(e[1]);
                 adj[e[1]].push_back(e[0]);
            }
        }
    
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        if(edge.size()<n-1)return -1;
        vis.resize(n,0);
        adj.resize(n);
        fillAdj(edge);
        int c=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i);
                c++;
            }
        }
        return c-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends