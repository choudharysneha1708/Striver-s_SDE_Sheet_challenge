//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
        vector<int>dis(N,INT_MAX);
        // vector<bool>vis(N,0);
        dis[0]=0;
        for(int i=0;i<M;++i){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto currVer = pq.top().second;
            auto d = pq.top().first;
            pq.pop();
            // vis[currVer]=1;
            for(auto child: adj[currVer]){
                int x=child.first;
                int l=child.second;
                if(dis[x]>d+l){
                    dis[x]=d+l;
                    pq.push({dis[x],x});
                }
                // if(!vis[x]){
                    
                // }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends