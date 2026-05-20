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
    void solve(TreeNode* root,TreeNode* parent,int key){
        if(root==NULL) return;
        if(root->val>key){
            parent=root;
            root=root->left;
            return solve(root,parent,key);
        }
        if(root->val<key){
            parent=root;
            root=root->right;
            return solve(root,parent,key);
        }
        if(root->val==key){
            if(parent==NULL){
                if(root->left==NULL) {
                TreeNode* x=root->right;
                parent=x;
                return;
            }
            else if(root->right==NULL){
                TreeNode* x=root->left;
                parent=x;
                return;
            }
            else{
                TreeNode* x=root->left;
                while(x->right) x=x->right;
                x->right=root->right;
                parent=root->left;
                return;
            }
            }
            else{
                if(root->left==NULL) {
               if(parent->right==root) parent->right=root->right;
               if(parent->left==root) parent->left=root->right;
               return;
            }
            else if(root->right==NULL){
               if(parent->right==root) parent->right=root->left;
               if(parent->left==root) parent->left=root->left;
               return;
            }
            else{
                if(parent->right==root) parent->right=root->left;
               if(parent->left==root) parent->left=root->left;
                TreeNode* x=root->left;
                while(x->right) x=x->right;
                x->right=root->right;
                return;
            }
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        TreeNode* parent =NULL;
        solve(root,parent,key);
        if(root->val==key){
            if(root->left) return root->left;
            else return root->right;
        }
        return root;
    }
};