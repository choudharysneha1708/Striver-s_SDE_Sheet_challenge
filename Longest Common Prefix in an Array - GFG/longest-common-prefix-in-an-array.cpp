//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string a[], int N)
    {
        sort(a, a+N);
        int i=0;
        string LongestCommonPrefix="";
        while(i<a[0].size() && i<a[N-1].size()){
            if(a[0][i]==a[N-1][i]){
                LongestCommonPrefix+=a[0][i];
                i++;
            }else{
                break;
            }
        }
        if(LongestCommonPrefix.size()==0)return "-1";
        return LongestCommonPrefix;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends