class Solution {
   void fill(vector<vector<int>>&adj,vector<int>&in ,vector<int>&leftChild,vector<int>&rightChild)
    {
        for(int i=0;i<leftChild.size();++i)
        {
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
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       int count = 0;
        for(int i=0; i<n; ++i){
            if(leftChild[i]!=-1){
                count++; 
            }
        }
        for(int i=0; i<n; ++i){
            if(rightChild[i]!=-1){
                count++;
            }
        }
        if((count+1)!=n)return 0;
        vector<int>in(n,0);
        vector<vector<int>> adj(n);
        fill(adj,in,leftChild, rightChild);
        queue<int>q;
        int root =-1;
        for(int i=0;i<n;++i)
        {
            if(!in[i] && root == -1){
                
                root = i;
            }
        }
        if(root == -1)return 0;
        q.push(root);
        int c=0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            c++;
            for(auto child: adj[node])q.push(child);
        }
        if(c==n)return 1;
        return 0;
    }
};