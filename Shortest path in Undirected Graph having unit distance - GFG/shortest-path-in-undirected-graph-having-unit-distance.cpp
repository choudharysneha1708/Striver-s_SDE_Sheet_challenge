//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int m, int src){
        vector<int>dis(N,INT_MAX);
        vector<bool>vis(N,0);
        dis[src]=0;
        vector<vector<int>>adj(N);
        for(int i=0;i<m;++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto currVer=pq.top().second;
            auto d=pq.top().first;
            pq.pop();
            vis[currVer]=1;
            for(auto child: adj[currVer]){
                if(dis[child]>d+1){
                    dis[child]=d+1;
                    if(!vis[child]) pq.push({dis[child],child});
                }
            }
        }
       for(int i=0;i<N;++i){
           if(dis[i]==INT_MAX){
               dis[i]=-1;
           }
       }
        return dis;
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