//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char x){
        if(x=='^')return 3;
        else if(x=='*' || x=='/')return 2;
        else if(x=='+' || x=='-')return 1;
        return 0;
    }
    bool isOperand(char s){
        if((s>='a' && s<='z') ||(s>='0' && s<='9'))return 1;
        return 0;
    }
    string infixToPostfix(string s) {
       stack<char>st;
       string x="";
       for(int i=0;i<s.size();++i){
           if(s[i]=='(')st.push(s[i]);
           else if(s[i]==')'){
               while(!st.empty() && st.top()!='('){
                   x+=st.top();
                   st.pop();
               }
               st.pop();
           }
           else if(isOperand(s[i]))x+=s[i];
           else{
               if(st.empty())st.push(s[i]);
               else{
                   int a=precedence(s[i]);
                   int y=precedence(st.top());
                   if(a>y)st.push(s[i]);
                   else{
                       while(!st.empty() && precedence(st.top())>=a){
                        //   cout<<x<<endl;
                           x+=st.top();
                           st.pop();
                       }
                       st.push(s[i]);
                   }
               }
           }
       }
       while(!st.empty()){
           x+=st.top();
           st.pop();
       }
       return x;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends