//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int t=0;
        int i=0;
        int j=0;
        int res=0;
        while(i<n){
            if(arr[i]==0)
            {
                if(t==m){
                    res=max(res,i-j);
                    
                    while(arr[j]!=0){
                        j++;
                    }
                    j++;
                }else{
                    t++;
                }
            }
            i++;
        }
        res=max(res,i-j);
        return res;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends