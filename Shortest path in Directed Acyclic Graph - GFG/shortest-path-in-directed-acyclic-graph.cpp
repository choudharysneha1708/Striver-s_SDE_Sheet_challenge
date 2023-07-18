//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  vector<int> find(vector<vector<pair<int,int>>>&adj, int src, int N){
      vector<int>Sortestdis(N, INT_MAX);
      Sortestdis[src]=0;
      queue<pair<int, int>>q;
      q.push({src, 0});
      while(!q.empty()){
          int currNode = q.front().first;
          int distance = q.front().second;
          q.pop();
          for(int i=0; i<adj[currNode].size(); ++i){
              if(Sortestdis[adj[currNode][i].first]>distance +adj[currNode][i].second){
                  q.push({adj[currNode][i].first, adj[currNode][i].second +distance});
                  Sortestdis[adj[currNode][i].first] = adj[currNode][i].second + distance;
              }
          }
      }
      for(int i=0; i<N; ++i){
            if(Sortestdis[i] == INT_MAX){
                Sortestdis[i] = -1;
            }
      }
      return Sortestdis;
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0; i<M; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            int edgeLen = edges[i][2];
            adj[x].push_back({y,edgeLen});
        }
        return find(adj, 0, N);
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