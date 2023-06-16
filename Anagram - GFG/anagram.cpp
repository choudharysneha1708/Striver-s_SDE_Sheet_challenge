//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t){
        if(s.size()!=t.size())return 0;
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        for(auto e: s){
            h1[e-'a']++;
        }
        for(auto e: t){
            h2[e-'a']++;
        }
        int i=0;
        while(i<26 && h1[i]==h2[i]){
            i++;
        }
        if(i!=26)return false;
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends