//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void find_All_premutation(string S, string currPremutaion, unordered_map<int,bool> &freq,set<string> &permutationOfString){
        if(currPremutaion.size()==S.size()){
            permutationOfString.insert(currPremutaion);
            return ;
        }
        for(int i=0; i<S.size();++i){
            if(!freq[i]){
                freq[i]=true;
                currPremutaion+=S[i];
                find_All_premutation(S,currPremutaion,freq,permutationOfString);
                currPremutaion.pop_back();
                freq[i]=false;
            }
        }
    }
    
    private: 
    vector<string> put(set<string>&permutationOfString){
        vector<string>ans;
        for(auto e:permutationOfString ){
            ans.push_back(e);
        }
        return ans;
    }
    
	public:
		vector<string>find_permutation(string S)
		{
            vector<string> s;
            string CurPremutation;
            unordered_map<int,bool> m;
             set<string>permutationOfString;
            find_All_premutation(S,CurPremutation,m,permutationOfString);

            return put(permutationOfString);
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends