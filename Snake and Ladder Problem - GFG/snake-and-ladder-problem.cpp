//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        map<int, int>snake;
        map<int, int>ladder;
        for(int i=0; i<2*N; i+=2){
            if(arr[i]>arr[i+1]){
                snake[arr[i]]= arr[i+1];
            }else{
                ladder[arr[i]]= arr[i+1];
            }
        }
        queue<int>q;
        q.push(1);

        int level = 0;
        vector<bool>vis(31,0);
        vis[1]=1;
       
        int res =INT_MAX;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                auto currNode = q.front();
                q.pop();
                if(currNode == 30) return  level;
                if(ladder.find(currNode) != ladder.end() && !vis[ladder[currNode]]){
                       int jump = currNode;
                        while(ladder.find(jump) != ladder.end()){
                           jump = ladder[jump];
                       }
                       if(!vis[jump]){
                           q.push(jump);
                           vis[jump]=1;
                       }
                }else if(snake.find(currNode) != snake.end() && !vis[snake[currNode]]){
                    q.push(snake[currNode]);
                    vis[snake[currNode]]=1;
                }
                else {
                   for(int j=1; j<=6 && (currNode+j)<=30; ++j){
                       int jump = currNode+j;
                       while(ladder.find(jump) != ladder.end()){
                           jump = ladder[jump];
                       }
                       if(!vis[jump]){
                           q.push(jump);
                           vis[jump]=1;
                       }
                   }
                }
            }
            level ++;
        }
        return res;
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