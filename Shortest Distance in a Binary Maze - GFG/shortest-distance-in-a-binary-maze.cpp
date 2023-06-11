//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int m,n;
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool check(int x,int y)
    {
        if(x<0 || y<0 || x>=n || y>=m)return 0;
        return 1;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> t) {
        // code here
         n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>>q;
        int le=0;
        int x=source.first;
        int y=source.second;
        if(grid[x][y]!=1)return -1;
        q.push({x,y});
         grid[x][y]=0;
        while(!q.empty())
        {
            int sz=q.size();
            // le++;
            for(int i=0;i<sz;++i)
            {
                int l=q.front().first;
                int m=q.front().second;
                q.pop();
                if(l==t.first && m==t.second)return le;
                for(int k=0;k<4;++k)
                {
                    int a=l+row[k];
                    int b=m+col[k];
                    if(check(a,b) && grid[a][b]==1)
                    {
                        q.push({a,b});
                        grid[a][b]=0;
                    }
                }
            }
            le++;
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