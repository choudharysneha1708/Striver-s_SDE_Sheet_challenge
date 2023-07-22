//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    	    vector<vector<int>>adj(N);
        vector<int>indgree(N,0);
	    for(int i=0; i<P; ++i){
	        adj[pre[i].second].push_back(pre[i].first);
	        indgree[pre[i].first]++;
	    }
        queue<int>q;
        for(int i=0; i<N; ++i){
            if(indgree[i]==0)q.push(i);
        }
        int c=0;
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            c++;
            for(auto e: adj[currNode]){
                indgree[e]--;
                if(indgree[e]==0)q.push(e);
            }
        }
        return c==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends