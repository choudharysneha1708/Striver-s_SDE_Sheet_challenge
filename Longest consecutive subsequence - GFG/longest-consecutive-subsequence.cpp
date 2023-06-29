//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    #define ll long long
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
        ll hash[100001];
        memset(hash, 0, sizeof(hash));
        for(int i=0; i<n; ++i){
            hash[arr[i]]++;
        }
        int maxLenth=0;
        int tempLenght=0;
        for(int i=0; i<100001; ++i){
            if(hash[i]==0){
                maxLenth= max(maxLenth, tempLenght);
                tempLenght=0;
            }else{
                tempLenght++;
            }
        }
        maxLenth= max(maxLenth, tempLenght);
        return maxLenth;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends