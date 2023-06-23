//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    int m,n;
    
    private: 
    bool check(int x, int y){
        if(x<0 || y<0 || x>=m || y>=n)return 0;
        return 1;
    }
    private: 
    int dfs(int x, int y, vector<vector<int>>&NoOfPath){
        if(x==m-1 && y==n-1)return 1;
        if(NoOfPath[x][y]!=-1)return NoOfPath[x][y];
        int path=0;
        if(check(x+1,y)) path+=dfs(x+1,y,NoOfPath );
        if(check(x,y+1))path+=dfs(x,y+1,NoOfPath );
        return NoOfPath[x][y]=path;
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        m=a,n=b;
        vector<vector<int>>NoOfPath(m,vector<int>(n,-1));
        return dfs(0,0,NoOfPath);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends