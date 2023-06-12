//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     vector<vector<int>>dis(n,(vector<int>(n,1e8)));
        for(int i=0;i<n;++i){
            dis[i][i]=0;
        }
       for(auto e: edges){
           int x=e[0];
           int y=e[1];
           int l=e[2];
           dis[x][y]=l;
           dis[y][x]=l;
       }
       for(int via=0;via<n;++via){
           for(int i=0;i<n;++i){
               for(int j=0;j<n;++j){
                   if(dis[i][j]>dis[i][via]+dis[via][j]){
                       dis[i][j]=dis[i][via]+dis[via][j];
                   }
               }
           }
       }
       int city_cnt=INT_MAX;
       int city=-1;
       for(int i=0;i<n;++i){
           int t=0;
           for(int j=0;j<n;++j){
               if(dis[i][j]!=0 && dis[i][j]<=distanceThreshold){
                   t++;
               }
           }
           if(t<=city_cnt ){
               city_cnt=t;
               city=i;
            //   cout<<t<<endl;
            //   cout<<city<<endl;
           }
       }
       return city;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends