//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string s1, string s2)
{
    int x =-1;
    int y = -1;
    if(s1.size()!=s2.size())return 0;
    for(int i=0; i<s1.size(); ++i){
        if(s1[i]!= s2[i]){
            if(x==-1){
                x =i;
            }else if(y==-1 && s2[x] ==s1[i] && s1[x]== s2[i]){
                y= i;
            }else return 0;
        }
    }
    if((x!= -1 && y== -1) || (x==-1))return 0;
    return 1;
}