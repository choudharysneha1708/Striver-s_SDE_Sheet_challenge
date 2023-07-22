//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(vector<int>adj[], int ver, int par, vector<bool>&vis){
        vis[ver] = true;
        bool check = false;
        for(auto child : adj[ver]){
            if(!vis[child]){
                check |= dfs(adj, child, ver, vis);
            }
            else if(vis[child] && child!=par)return true;
            
        }
        return check;
    }
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V, 0);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                if(dfs(adj, i, -1, vis))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends