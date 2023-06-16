//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
         if(s.size()!=t.size())return false;
        map<char,char>m;
        unordered_set<char>st;
        int i=0;
        while(i<s.size()){
            if(m.find(s[i])==m.end()){
                if(st.find(t[i])!=st.end())return false;
                m[s[i]]=t[i];
                st.insert(t[i]);
            }else{
                if(m[s[i]]!=t[i])return false;
            }
            i++;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends