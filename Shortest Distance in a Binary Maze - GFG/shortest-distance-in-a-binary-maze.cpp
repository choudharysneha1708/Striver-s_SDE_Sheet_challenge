//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int n,m;
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
  private:
    bool check(int x, int y){
        if(x<0 || y<0 || x>=n || y>=m)return 0;
        return 1;
    }
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> sou,
                     pair<int, int> des) {
        // code here
        n=grid.size();
        m=grid[0].size();
        int level=0;
        queue<pair<int,int>>q;
        q.push({sou.first,sou.second});
        grid[sou.first][sou.second]=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;++i){
                int x= q.front().first;
                int y=q.front().second;
                if(x==des.first && y==des.second)return level;
                q.pop();
                for(int k=0;k<4;++k){
                    int a= row[k]+x;
                    int b=col[k]+y;
                    if(check(a,b) && grid[a][b]==1){
                        q.push({a,b});
                        grid[a][b]=0;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends