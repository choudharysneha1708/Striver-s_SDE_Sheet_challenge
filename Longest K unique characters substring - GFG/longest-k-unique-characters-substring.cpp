//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    private:
    int AtMostK(string s, int k){
        int maxL =0;
        unordered_map<char, int>m;
        int l = 0;
        int r = 0;
        while(r<s.size()){
            m[s[r]]++;
            while(m.size()>k){
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
            if(m.size()==k) maxL= max(maxL,(r-l+1));
            r++;
        }
        if(maxL==0)return -1;
        return maxL;
    }
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     return AtMostK(s,k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends