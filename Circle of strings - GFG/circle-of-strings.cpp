//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    private:
    void dfs(int ver, vector<bool>&vis,unordered_map<int, vector<int>>&adj, stack<int>&st){
        vis[ver] = 1;
        for(auto child : adj[ver]){
            if(!vis[child]){
                dfs(child, vis, adj, st);
            }
        }
        st.push(ver);
    }
     private : 
    void Tdfs(int ver, vector<bool>&vis, unordered_map<int, vector<int>>&TAdj){
        vis[ver] = 1;
        for(auto child : TAdj[ver]){
            if(!vis[child]){
                Tdfs(child, vis, TAdj);
            }
        }
    }
    public:
    int isCircle(int N, vector<string> A)
    {
        vector<int>in(26, 0);
        unordered_map<int, vector<int>>adj;
        for(int i=0; i<N; ++i){
            int n = A[i].size();
            adj[(A[i][0]-'a')].push_back((A[i][n-1])-'a');
            in[(A[i][n-1])-'a']++;
        }
        for(auto e: adj){
            if(e.second.size() != in[e.first])return 0;
        }
        int V= 26;
        vector<bool>vis(V,0);
        stack<int>st;
        for(int i=0; i<V; ++i){
            if(!vis[i] && adj.find(i) != adj.end()){
                dfs(i,vis, adj, st);
            }
        }
        unordered_map<int, vector<int>>TAdj;
        for(auto e: adj){
            for(auto child : e.second){
                TAdj[child].push_back(e.first);
            }
        }
        for(int i=0; i<V;++i)vis[i]=0;
        int count =0;
        while(!st.empty()){
            auto currNode = st.top();
            st.pop();
            if(!vis[currNode]){
                Tdfs(currNode, vis, TAdj);
                count ++;
            }
        }
        
        return count == 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends