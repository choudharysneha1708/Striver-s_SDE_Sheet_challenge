//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 class Solution {
public:
    int m,n; 
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool check(int x, int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)return 0;
        return 1;
    }
    int MinimumEffort(vector<vector<int>>& height) {
        m=height.size();
        n=height[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        //  vector<vector<bool>>vis(m,vector<bool>(n,0));
        dis[0][0]=0;
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>, greater <pair<int, pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x= pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            // if(vis[x][y])continue;
            // vis[x][y]=1; 
            for(int i=0;i<4;++i)
            {
                int a=x+row[i];
                int b=y+col[i];
                if(check(a,b))
                {
                    int newEff=max(d,abs(height[a][b]-height[x][y]));
                    if(dis[a][b]>newEff)
                    {
                        dis[a][b]=newEff;
                        pq.push({dis[a][b],{a,b}});
                     
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends