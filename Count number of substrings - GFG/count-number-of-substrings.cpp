//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    long long int count_of_subString_Of_atmost_k_distinct_char(string s, int k){
        vector<long long int>h(26,0);
        long long int i=0;
        long long int  j=0;
        long long int count=0;
        long long int  disElement=0;
        while(i<s.size()){
            if(h[s[i]-'a']==0)disElement++;
            h[s[i]-'a']++;
            if(disElement>k){
                while(disElement>k){
                    h[s[j]-'a']--;
                    if(h[s[j]-'a']==0)disElement--;
                    j++;
                }
            }
            count+=(i-j+1);
            i++;
        }
        return count;
    }
  public:
    long long int substrCount (string s, int k) {
        return count_of_subString_Of_atmost_k_distinct_char(s,k)-count_of_subString_Of_atmost_k_distinct_char(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends