//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    Node* markParent(Node* root, unordered_map<Node*, Node*>&m, int t){
        queue<Node*>q;
        q.push(root);
        Node* target;
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            if(currNode->left){
                q.push(currNode->left);
                m[currNode->left]= currNode;
            }
            if(currNode->right){
                q.push(currNode->right);
                m[currNode->right]= currNode;
            }
            if(currNode->data== t)target = currNode;
        }
        return target;
    }
private: 
    vector<int>PrintNodes(Node* root,unordered_map<Node*, Node*>&m, int k){
        unordered_set<Node*>s;
        queue<Node*>q;
        q.push(root);
        s.insert(root);
        int level = 0;
        vector<int> nodes;
        while(!q.empty() && level<=k){
           int size = q.size();
           for(int i=0; i<size; ++i){
                auto currNode = q.front();
                q.pop();
                if(currNode->left && s.find(currNode->left) == s.end()){
                    q.push(currNode->left);
                    s.insert(currNode->left);
                }
                 if(currNode->right && s.find(currNode->right) == s.end()){
                    q.push(currNode->right);
                    s.insert(currNode->right);
                }
                 if(m.find(currNode)!= m.end() && s.find(m[currNode]) ==s.end()) {
                    q.push(m[currNode]);
                    s.insert(m[currNode]);
                }
                if(level == k){
                    nodes.push_back(currNode->data);
                }
           }
           level ++;
        }
        sort(nodes.begin(), nodes.end());
        return nodes;
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*, Node*>parent;
        Node* newRoot= markParent(root, parent,  target);
        return PrintNodes(newRoot, parent, k);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends