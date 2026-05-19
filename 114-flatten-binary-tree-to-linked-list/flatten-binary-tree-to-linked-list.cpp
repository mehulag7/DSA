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
    TreeNode* solve(TreeNode* root){
        if(root==NULL) return root;
        TreeNode* x=solve(root->left);
        TreeNode* y=solve(root->right);
        root->left=NULL;
        root->right=x;
         while(x && x->right) x=x->right;
         if(x!=NULL){
            x->right=y;
            return root;
         }
         else{
            root->right=y;
            return root;
         }
    }
    void flatten(TreeNode* root) {
         solve(root);
    }
};