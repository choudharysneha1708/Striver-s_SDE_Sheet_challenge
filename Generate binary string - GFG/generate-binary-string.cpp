//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    void generate(string s, int index, vector<string >&ans){
        if(index==s.size()){
            ans.push_back(s);
            return ;
        }
        if(s[index]=='?'){
            string s1= s;
            string s2 = s;
            s1[index]= '1';
            s2[index]='0';
            generate(s1, index+1,ans);
            generate(s2,index+1, ans);
        }else{
            generate(s, index+1, ans);
        }
        return ;
    }
	public:
		vector<string> generate_binary_string(string s)
		{
            vector<string>ans;
            generate(s, 0, ans);
            sort(ans.begin(), ans.end());
            return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends