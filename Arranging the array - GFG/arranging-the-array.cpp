//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int N)
        {
            vector<int>p;
            vector<int>n;
            for(int i=0;i<N;++i){
                if(arr[i]<0)n.push_back(arr[i]);
                else p.push_back(arr[i]);
            }
            int i=0;
            int j=0;
            while(i<n.size()){
                arr[j]=n[i];
                j++;
                i++;
            }
            i=0;
            while(i<p.size()){
                arr[j]=p[i];
                j++;
                i++;
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends