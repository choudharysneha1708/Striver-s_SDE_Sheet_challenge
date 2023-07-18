//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<int>toposort(vector<vector<int>>&adj, int k){
        vector<int>indegree(k,0);
        vector<int>Order;
        queue<int>q;
        for(int i=0; i<k; ++i){
            for(auto e : adj[i]){
                indegree[e]++;
            }
        }
        for(int i=0; i<k; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            Order.push_back(currNode);
            for(int i=0 ; i<adj[currNode].size(); ++i){
                indegree[adj[currNode][i]]--;
                if(indegree[adj[currNode][i]] == 0){
                    q.push(adj[currNode][i]);
                }
            }
        }
        return Order;
    }
    public:
    string findOrder(string dict[], int N, int k) {
        vector<vector<int>>adj(k);
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int minLen = min(s1.size(), s2.size());
            for(int i=0; i<minLen; i++){
                if(s1[i] != s2[i]){
                    adj[s1[i] -'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        string Order = "";
        vector<int>topo =toposort(adj, k);
        for(int i=0 ; i<topo.size(); ++i){
            Order+= (topo[i]+'a');
        }
        return Order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends