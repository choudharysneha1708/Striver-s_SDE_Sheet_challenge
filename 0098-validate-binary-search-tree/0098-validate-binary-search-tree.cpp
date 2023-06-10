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
    bool check(TreeNode* root, long upper_bound, long lower_bound){
        if(root==NULL)return true;
        if(root->val>=upper_bound || root->val<=lower_bound)return false;
        return check(root->left,root->val,lower_bound) && check(root->right,upper_bound,root->val);
    }
    bool isValidBST(TreeNode* root) {

        return check(root,2147483649,-2147483649);
    }
};