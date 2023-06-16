//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
       int depth=0;
        stack<char>st;
        for(auto e: s){
            if(e=='(')st.push(e);
            else if(e==')'){
                if(st.size()>depth)depth=st.size();
                st.pop();
            }else {
                continue;
            }
        }
        return depth;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends