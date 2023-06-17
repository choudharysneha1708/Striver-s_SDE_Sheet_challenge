//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        s+='.';
        stack<string>st;
        string t="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='.'){
                st.push(t);
                t="";
            }else{
                t+=s[i];
            }
            i++;
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            s+='.';
            st.pop();
        }
        s.pop_back();
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends