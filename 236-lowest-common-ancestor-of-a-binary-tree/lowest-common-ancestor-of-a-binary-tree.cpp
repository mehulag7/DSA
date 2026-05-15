/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* path(TreeNode* x,TreeNode* q,TreeNode* p){
        if(x==NULL) return NULL;
       if(x==p || x==q){
           return x;
       }
       else{
        TreeNode* k=path(x->left,q,p);
        TreeNode* j=path(x->right,q,p);
        if(!k){
            return j;
        }
        else{
            if(!j) return k;
            else return x;
        }
       }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x=path(root,p,q);
        return x;
    }
};