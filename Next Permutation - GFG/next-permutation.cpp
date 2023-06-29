//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){
        int x=-1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                x=i-1;
                break;
            }
        }
        if(x==-1)
        {
            sort(nums.begin(),nums.end());
        }
        else
        {
            for(int i=nums.size()-1;i>x;i--)
            {
                if(nums[i]>nums[x]){
                    swap(nums[i],nums[x]);
                    reverse(nums.begin()+x+1,nums.end());
                    break;
                }
            }
        }
       return nums; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends