//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
       unordered_map<int,int>m;
       for(int i=0; i<2*N; i+=2){
           m[arr[i]]= arr[i+1];
       }
       queue<int>q;
       vector<bool>vis(31,0);
       q.push(1);
       int level = 0;
       while(!q.empty()){
           int size = q.size();
           while(size--){
               auto currNode = q.front();
               if(currNode==30)return level;
               q.pop();
               for(int j=1; j<=6; ++j){
                   int jump = currNode+ j;
                   while(m.find(jump)!=m.end()){
                       jump = m[jump];
                   }
                   if(!vis[jump]){
                       q.push(jump);
                       vis[jump] =1;
                   }
               }
           }
           level++;
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends