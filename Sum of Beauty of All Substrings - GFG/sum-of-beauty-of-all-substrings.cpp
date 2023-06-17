//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
//   private: 
//     int beauty(unordered_map<char,int>&hash){
//         int mostFreq=INT_MIN;
//         int leastFreq=INT_MAX;
//         for(auto e: hash){
            
//                 leastFreq=min(leastFreq,e.second);
//                 mostFreq=max(mostFreq,e.second);
            
//         }
//         if(mostFreq!=INT_MIN)return mostFreq-leastFreq;
//         return 0;
//     }
  public:
    int beautySum(string s) {
        
        // Your code goes here
        long long cnt = 0;
        for(int i=0;i<s.size();i++){
            vector<int>v(26,0);
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j=i;j<s.size();j++){
                v[s[j]-'a']++;
                maxi = max(maxi,v[s[j]-'a']);
                mini = v[s[j]-'a'];
                for(int k=0;k<26;k++){
                    if(v[k]>=1){
                        mini = min(mini,v[k]);
                    }
                }
                cnt+=(maxi-mini);
            }
        }  
        return (int)cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends