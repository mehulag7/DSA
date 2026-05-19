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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x=root;
        if(x==NULL) {
            x=new TreeNode(val);
            return x;
        }
        while(x){
            if(x->val>val){
              if(x->left!=NULL)  x=x->left;
              else{
                x->left=new TreeNode(val);
                return root;
              }
            }
            else{
                 if(x->right!=NULL)  x=x->right;
              else{
                x->right=new TreeNode(val);
                return root;
              }
            }
        }
        return root;
    }
};