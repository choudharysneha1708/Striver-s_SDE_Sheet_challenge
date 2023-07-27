//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    bool LCS(string &a, string &b){
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
           if(a[i]==b[j])i++,j++;
           else i++;
        }
        if(j==b.size())return 1;
        return 0;
    }
  public:
    string findLongestWord(string S, vector<string> d) {
        // code here
        int maxL = 0;
        string res= "";
        int n= S.size();
        for(int i=0; i<d.size(); ++i){
            if(LCS(S, d[i]) && maxL<d[i].size()){
                maxL = d[i].size();
                res = d[i];
            }else if(LCS(S, d[i]) && maxL==d[i].size()){
                res = min(res, d[i]);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++) cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends