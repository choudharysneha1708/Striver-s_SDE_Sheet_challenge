//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int fun(string s);

int main() {
    int tt;
    string s;
    cin >> tt;
    while (tt--) {
        cin >> s;
        cout<<fun(s)<<endl;
        
    }
    return 0;
}
// } Driver Code Ends


int fun(string s)
{
    unordered_set<string>distinct;
    for(int i=1; i<s.size(); ++i)
    {
        string x = "";
        x+=s[i-1];
        x+=s[i];
        distinct.insert(x);
    }
    return distinct.size();
}