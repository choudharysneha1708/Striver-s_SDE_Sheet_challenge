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
    TreeNode* build(int &index, vector<int>& preorder, int upperBound){
        if(index==preorder.size() || preorder[index]>upperBound )return NULL;
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left=build(index,preorder,root->val);
        root->right=build(index,preorder,upperBound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        int upperBound=1001;
        return build(index,preorder,upperBound);
    }
};