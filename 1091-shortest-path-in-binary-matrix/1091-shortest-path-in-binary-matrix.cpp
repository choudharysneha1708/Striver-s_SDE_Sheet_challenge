class Solution {
public:
    int m,n;
    int row[8]={1,-1,0,0,1,1,-1,-1};
    int col[8]={0,0,1,-1,1,-1,1,-1};
    bool check(int x,int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        queue<pair<int,int>>q;
        int l=0;
        if(grid[0][0]!=0)return -1;
        q.push({0,0});
         grid[0][0]=1;
        while(!q.empty())
        {
            int sz=q.size();
            l++;
            for(int i=0;i<sz;++i)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 && y==n-1)return l;
                for(int k=0;k<8;++k)
                {
                    int a=x+row[k];
                    int b=y+col[k];
                    if(check(a,b) && grid[a][b]==0)
                    {
                        q.push({a,b});
                        grid[a][b]=1;
                    }
                }
            }
            
        }
        return -1;
    }
};