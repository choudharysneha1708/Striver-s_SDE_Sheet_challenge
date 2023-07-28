//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int XOR=0;
        for(int i=0; i<nums.size(); ++i){
            XOR^=nums[i];
        }
        XOR= (XOR & ~(XOR-1));  //right most set digit of xor of both distinct number 
        int set1 =0;
        int set2 =0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]&(XOR)){
                set1^=nums[i];
            }else {
                set2^=nums[i];
            }
        }
        vector<int>res;
        res.push_back(set1);
        res.push_back(set2);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends