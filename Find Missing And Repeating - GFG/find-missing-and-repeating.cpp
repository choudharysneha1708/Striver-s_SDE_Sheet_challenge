//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>v;
        for(int i=0; i<n; ++i){
            int ind= abs(arr[i])-1;
            if(arr[ind]>0){
                arr[ind]*=-1;
            }else{
                v.push_back(ind+1);
            }
        }
        for(int i=0; i<n; ++i){
            if(arr[i]>0)v.push_back(i+1);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends