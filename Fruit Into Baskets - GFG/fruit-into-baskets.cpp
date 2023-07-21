//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        unordered_map<int,int>m;
        int MaxFruits =0;
        int start =0;
        int end = 0;
        while(end<N){
            m[fruits[end]]++;
            // end++;
            if(m.size()>2){
                while(m.size()>2){
                    m[fruits[start]]--;
                    if(m[fruits[start]]==0){
                        m.erase(fruits[start]);
                    }
                    start++;
                }
            }
            MaxFruits = max(MaxFruits, end-start+1);
            end++;
        }
        return MaxFruits;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends