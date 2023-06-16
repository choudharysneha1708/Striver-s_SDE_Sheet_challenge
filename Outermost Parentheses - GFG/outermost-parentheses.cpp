//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        string res="";
        int i=0;
        stack<char>st;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
                if(st.size()>1)res+=s[i];
            }else{
                if(st.size()>1){
                    res+=s[i];
                }
                st.pop();
            }
            i++;
        }
        return res;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends