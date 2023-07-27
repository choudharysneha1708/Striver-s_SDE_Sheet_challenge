//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(int ver, vector<int>adj[], vector<bool>vis, int par){
        vis[ver]=1;
        for(auto child: adj[ver]){
            
            if(vis[child] && child!= par)return 1;
            else if(!vis[child]){
                if(detect(child, adj,vis, ver))return 1;
            }
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V, 0);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                if(detect(i,adj,vis,-1))return 1;
            }
        }
        return 0;
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