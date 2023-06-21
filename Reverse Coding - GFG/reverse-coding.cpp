//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        int m=1e9+7;
    // long long mod(int x){
    //     return (((x%m)+m)%m);
    // }
    int sumOfNaturals(int n) {
        // code here
        // if(n%2)return mod(mod(n)*mod((n+1)/2));
        // return mod(mod(n/2)*mod(n+1));
        return ((n*1LL*(n+1))/2)%m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends