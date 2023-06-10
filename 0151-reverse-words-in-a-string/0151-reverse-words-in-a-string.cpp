class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        s+=' ';
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')continue;
            string t="";
            while(s[i]!=' ')
            {
                t+=s[i];i++;
            }
            st.push(t);
        }
        s="";
        while(!st.empty())
        {
            string t=st.top();
            st.pop();
            s+=t;
            s+=' ';
        }
        s.pop_back();
        return s;
    }
};