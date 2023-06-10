//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string num) {
        int j=-1;
        for(int i=0;i<num.size();++i)
        {
            int x=num[i]-'0';
            if(x%2==1)
            {
               j=i; 
            }
        }
        if(j==-1)return "";
        string s=num.substr(0,j+1);
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends