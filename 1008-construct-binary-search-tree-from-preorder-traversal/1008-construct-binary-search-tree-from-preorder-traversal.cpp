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
public:
    TreeNode* buildTree(vector<int>& preorder,int bound, int & index){
        if(index==preorder.size() || preorder[index]>bound)return NULL;
        TreeNode* root= new TreeNode(preorder[index++]);
        root->left=buildTree(preorder,root->val,index);
        root->right=buildTree(preorder,bound,index);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int bound=INT_MAX;
        int index=0;
        return buildTree(preorder,bound,index);
    }
};