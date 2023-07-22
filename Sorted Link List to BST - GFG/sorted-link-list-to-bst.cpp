//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
    private:
    LNode* findMid(LNode* head){
        LNode *slow = head;
        LNode * fast = head;
        while(fast != NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next; 
        }
        return slow;
    }
    private: 
    LNode* makefirstHalf(LNode* head, LNode* mid){
        if(head==mid)return NULL;
        LNode* temp = head;
        while(temp->next != mid){
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
    private:
    TNode* constructBSt(LNode* head){
        if(head== NULL)return NULL;
        LNode* mid = findMid(head);
        TNode* root = new TNode(mid->data);
        LNode *left = makefirstHalf(head, mid);
        LNode* right = mid->next;
        root->left = constructBSt(left);
        root->right = constructBSt(right);
        return root;
    }
  public:
    TNode* sortedListToBST(LNode *head) {
        return constructBSt(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends