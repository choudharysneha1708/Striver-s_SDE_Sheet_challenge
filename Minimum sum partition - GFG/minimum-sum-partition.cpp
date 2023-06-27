//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0; i<n; ++i)sum+=arr[i];
	    vector<bool>prev(sum+1, 0);
	    prev[0]=1;
	    for(int i=1;i<=n; ++i){
	        vector<bool>curr(sum+1,1);
	        for(int j=1; j<=sum; ++j){
	            if(arr[i-1]<=j){
	                curr[j]=prev[j-arr[i-1]]|| prev[j];
	            }else{
	                curr[j]=prev[j];
	            }
	        }
	        prev=curr;
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<=sum; ++i){
	      if(prev[i]){
	          mini=min(abs(sum-2*i) , mini);
	      }  
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends