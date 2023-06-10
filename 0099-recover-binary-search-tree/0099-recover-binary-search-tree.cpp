/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void inorder(TreeNode* root, vector<int>&in){
        if(!root)return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
private: 
    void doCorrect(TreeNode* root, vector<int>&in, int & index){
        if(!root)return ;
        doCorrect(root->left, in,index);
        if(root->val!=in[index]){
            root->val=in[index++];
        }
        else{
            index++;
        }
        doCorrect(root->right, in,index);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        sort(in.begin(), in.end());
        int index=0;
        doCorrect(root,in,index);
    }

};