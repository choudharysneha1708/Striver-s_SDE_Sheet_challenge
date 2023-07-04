//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
ll inversion;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(ll a[], ll l, ll mid, ll r){
        vector<ll> final(r-l+1);
        ll i=l;
        ll j=mid+1;
        ll k=0;
        while(i<=mid && j<=r){
            if(a[i]>a[j]){
                inversion+=(mid-i+1);
                final[k++]=a[j++];
            }else{
                
                final[k++]=a[i++];
            }
        }
        while(i<=mid)final[k++]=a[i++];
        while(j<=r)final[k++]=a[j++];
        for(int m=l; m<=r; ++m){
            a[m]=final[m-l];
        }
    }
    void MergeSort( ll a[], ll l, ll r){
        if(l>=r)return ;
        ll mid = l+(r-l)/2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        inversion=0;
        MergeSort(arr, 0,N-1);
        return inversion;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends