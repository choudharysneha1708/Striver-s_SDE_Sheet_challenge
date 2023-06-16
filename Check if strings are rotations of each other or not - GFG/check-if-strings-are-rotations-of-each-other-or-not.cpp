//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s,string goal)
    {
       if(s.size()!=goal.size())return false;
        int n=s.size();
        int j=0;//pointer on goal string
        int i=0;//pointer on s
        while(i<s.size()){
            if(s[i]==goal[j]){
                // j++;
                int f=0;
                for(int k=i+1 ;(k)%n!=i;k++){
                    j++;
                    if(s[(k)%n]!=goal[j]){
                        f=1;
                        break;
                    }else{
                                           
                    }
                }
                if(f){
                    j=0;
                }else {
                    return true;
                }
            }
            i++;
        }
      
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends