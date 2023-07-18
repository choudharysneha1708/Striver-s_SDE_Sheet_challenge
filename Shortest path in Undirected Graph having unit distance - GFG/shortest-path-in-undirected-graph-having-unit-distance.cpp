//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>sortestPathfromSrc(N, INT_MAX);
        vector<vector<int>>adj(N);
        for(int i=0 ; i<M; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        sortestPathfromSrc[src] = 0;
        queue<pair<int, int>>q;
        q.push({src, 0});
        while(!q.empty()){
            auto currNode = q.front().first;
            int dis =q.front().second;
            q.pop();
            // if(sortestPathfromSrc[curr])
            for(int i=0; i<adj[currNode].size(); ++i){
                if(sortestPathfromSrc[adj[currNode][i]]> dis+1){
                    sortestPathfromSrc[adj[currNode][i]] = dis + 1;
                    q.push({adj[currNode][i], dis+1});
                }
            }
        }
        for(int i=0; i<N; ++i){
            if(sortestPathfromSrc[i] == INT_MAX){
                sortestPathfromSrc[i] = -1;
            }
        }
        return sortestPathfromSrc;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends