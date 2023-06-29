//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
    long long pairWithMaxSum(long long arr[], long long n)
    {
        long long MaxSum=LONG_MIN;
        long long CurrSum=arr[0];
        for(int i=1; i<n; ++i){
            CurrSum+=arr[i];
            MaxSum= max(MaxSum, CurrSum);
            CurrSum-=arr[i-1];
        }
        return MaxSum;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends