//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
       int n=N;
       vector<int>prev(n);
       for(int i=0; i<n; ++i)prev[i]=matrix[n-1][i];
       vector<int>curr(n);
       for(int i=n-2; i>=0; i--){
           for(int j=0; j<n; ++j){
               curr[j]=prev[j]+matrix[i][j];
               if(j>0){
                   curr[j]=max(curr[j], prev[j-1]+matrix[i][j]);
               }
               if(j<n-1){
                   curr[j]=max(curr[j], prev[j+1]+matrix[i][j]);
               }
           }
           prev=curr;
       }
       int minSumPath=INT_MIN;
       for(int i=0; i<n; ++i){
           minSumPath=max(minSumPath, prev[i]);
       }
       return minSumPath;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends