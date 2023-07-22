//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

private:
    bool color(vector<int>&vis, int ver, vector<int>adj[], int col){
        vis[ver] = col;
        for(auto child : adj[ver]){
            if(vis[child] == -1){
                if(color(vis, child, adj, (!col)) == false)return 0;
            }
            else if(vis[child]== col)return 0;
        }
        return 1;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V,-1);
        for(int i=0; i<V; ++i){
            if(vis[i] == -1){
                if(!(color(vis, i, adj, 1)))return 0;
            }
        }
        return 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends