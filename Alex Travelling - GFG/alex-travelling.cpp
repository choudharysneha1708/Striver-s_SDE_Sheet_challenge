//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    int findMaxTimeTo_reach(vector<int>& time){
        int t=INT_MIN;
        for(auto e: time){
          
                t=max(e,t);
        }
        return t;
    }
  public:
    int minimumCost(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);// u->(v,t)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;//dis,node
        for(auto e: times){
            adj[e[0]-1].push_back({e[1]-1,e[2]});
        }
        pq.push({0,k-1});
        time[k-1]=0;
        while(!pq.empty()){
            auto currT=pq.top().first;
            auto L=pq.top().second;
            pq.pop();
            for(auto e: adj[L]){
                auto dest= e.first;
                auto t=e.second;
                int newT=currT+t;
                if(time[dest]>newT){
                    time[dest]=newT;
                    pq.push({newT,dest});
                }
            }
        }
        int t=findMaxTimeTo_reach(time);
        if(t==INT_MAX)return -1;
        return t;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends