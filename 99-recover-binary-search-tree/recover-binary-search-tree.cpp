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
    TreeNode* left;
    TreeNode* middle;
    TreeNode* right;
    TreeNode* prev;
    void traversal(TreeNode* root){
       if(!root) return;
       traversal(root->left);
       if(prev!=NULL && root->val<prev->val){
        if(left==NULL){
            left=prev;
            middle=root;
        }
        else right=root;
       }
       prev=root;
       traversal(root->right);
    } 
    void recoverTree(TreeNode* root) {
        left=right=middle=prev=NULL;
        traversal(root);
        if(left && right){
            int a=left->val;
            left->val=right->val;
            right->val=a;
        }
        else{
            right=middle;
        int a=left->val;
            left->val=right->val;
            right->val=a;
        }
        return;
    }
};