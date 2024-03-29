//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(), intervals.end());
         vector<vector<int>>merge;
         int a = intervals[0][0];
         int b = intervals[0][1];
         for(int i=1; i<intervals.size(); ++i){
             if(b>= intervals[i][0] && b<=intervals[i][1]){
                 b= intervals[i][1];
             }else if(b<intervals[i][0]){
                 merge.push_back({a,b});
                 a = intervals[i][0];
                 b = intervals[i][1];
             }
         }
                          merge.push_back({a,b});
         return merge;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends