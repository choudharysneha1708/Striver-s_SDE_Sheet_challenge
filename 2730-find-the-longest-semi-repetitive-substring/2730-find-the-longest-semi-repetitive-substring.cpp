class Solution {
public:
    
int longestSemiRepetitiveSubstring(string s) {
        int res=INT_MIN;
        int i=1;
        int j=0;  //start
        int k=-1;//position
        // unordered_map<char,int>m;
        int f=0;
        while(i<s.size()){
            // m[s[i]]++;
            if(s[i]==s[i-1] && f==0){
                f=1;
                k=i;
            }
            else if(f==1 &&s[i]==s[i-1] ){
                res=max(res,i-j);
               j=k;
                k=i;
                // j++;   
            }
            i++;
        }
        res=max(res,i-j);
        return res;
}

};