class Solution {
   void fill(vector<vector<int>>&adj,vector<int>&in ,vector<int>&leftChild,vector<int>&rightChild)
    {
        for(int i=0;i<leftChild.size();++i)
        {
            // adj[p[i][1]].push_back(p[i][0]);
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                in[leftChild[i]]++;
            }
             if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                in[rightChild[i]]++;
            }
        }
    }
    private:
    void change(int &x, int &y){
        if(x>y){
           int t=x;
            x=y;
            y=t;
        }
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       int count = 0;
        map<pair<int,int>,int>m;
        for(int i=0; i<n; ++i){
            if(leftChild[i]!=-1){
                count++;
                int x =i;
                int y =leftChild[i];
                change(x,y);
                m[{x,y}]++;
                if(m[{x,y}]>1)return 0;
            }
        }
        for(int i=0; i<n; ++i){
            if(rightChild[i]!=-1){
                count++;
                int x =i;
                int y =rightChild[i];
                change(x,y);
                m[{x,y}]++;
                if(m[{x,y}]>1)return 0;
            }
        }
        if((count+1)!=n)return 0;
        vector<int>res;
        vector<int>in(n,0);
        vector<vector<int>> adj(n);
        fill(adj,in,leftChild, rightChild);
        queue<int>q;
        int c=0;
        int root =-1;
        for(int i=0;i<n;++i)
        {
            if(!in[i] && root == -1){
                
                root = i;
            }
        }
        if(root == -1)return 0;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            c++;
            for(auto child: adj[node]){
                q.push(child);
            }
        }
        if(c==n)return 1;
        // return {};
        return 0;
    }
};