class Solution {
public:
    string largestOddNumber(string num) {
        int j=-1;
        for(int i=0;i<num.size();++i)
        {
            int x=num[i]-'0';
            if(x%2==1)
            {
               j=i; 
            }
        }
        if(j==-1)return "";
        string s=num.substr(0,j+1);
        return s;
    }
};