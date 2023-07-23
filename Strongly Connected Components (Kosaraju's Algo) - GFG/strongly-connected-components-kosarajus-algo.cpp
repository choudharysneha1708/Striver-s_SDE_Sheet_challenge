//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int ver, vector<bool>&vis, vector<vector<int>>&adj, stack<int>&st){
        vis[ver] = 1;
        for(auto child : adj[ver]){
            if(!vis[child]){
                dfs(child, vis, adj, st);
            }
        }
        st.push(ver);
    }
    private : 
    void Tdfs(int ver, vector<bool>&vis, vector<vector<int>>&adj){
        vis[ver] = 1;
        for(auto child : adj[ver]){
            if(!vis[child]){
                Tdfs(child, vis, adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool>vis(V,0);
        stack<int>st;
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                dfs(i,vis, adj, st);
            }
        }
        vector<vector<int>>TAdj(V);
        for(int i=0; i<V; ++i){
            for(auto child: adj[i]){
                TAdj[child].push_back(i);
            }
        }
        for(int i=0; i<V;++i)vis[i]=0;
        int count =0;
        while(!st.empty()){
            auto currNode = st.top();
            st.pop();
            if(!vis[currNode]){
                Tdfs(currNode, vis, TAdj);
                count ++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends