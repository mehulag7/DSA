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
    TreeNode* solve(int i,int j,vector<int>& preorder){
        if(i>j) return NULL;
        if(i==j) {
            TreeNode* x=new TreeNode(preorder[i]);
            return x;
        }
        int t=i+1;
        for(;t<=j;t++) if(preorder[t]>preorder[i]) break;
        TreeNode* x=new TreeNode(preorder[i]);
        x->left=solve(i+1,t-1,preorder);
        x->right=solve(t,j,preorder);
        return x;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int j=preorder.size()-1;
       return solve(i,j,preorder);
    }
};