//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void find_All_premutation(int index,string S,set<string> &permutationOfString){
        if(index==S.size()){
            permutationOfString.insert(S);
            return ;
        }
        for(int i=index; i<S.size();++i){
            swap(S[i],S[index]);
            find_All_premutation(index+1,S,permutationOfString);
            swap(S[i],S[index]);
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
            find_All_premutation(0,S,permutationOfString);

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