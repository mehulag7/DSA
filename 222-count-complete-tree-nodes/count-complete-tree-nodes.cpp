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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=1,rh=1;
        TreeNode* x=root;
        while(x->left) {
            x=x->left;
            lh++;
        }
        x=root;
        while(x->right) {
            x=x->right;
            rh++;
        }
        if(lh==rh){
            return (1<<lh)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};