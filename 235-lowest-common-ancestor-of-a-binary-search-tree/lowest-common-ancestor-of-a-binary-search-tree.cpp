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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        int a=p->val;
        int b=q->val;
        int c=max(a,b);
        a=min(a,b);
        b=c;
        TreeNode* x=root;
        while(x){
            if(x->val>=a && x->val<=b) return x;
            else{
                if(x->val<a) x=x->right;
                else x=x->left;
            }
        }
        return root;
    }
};