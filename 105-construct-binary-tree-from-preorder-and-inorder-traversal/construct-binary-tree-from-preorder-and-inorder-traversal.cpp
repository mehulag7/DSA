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
    TreeNode* solve(vector<int>&preorder,int i,int j,vector<int>&inorder,int a,int b,map<int,int> &mpp){
        if(i>j) return NULL;
        if(i==j){
             TreeNode* c=new TreeNode(preorder[i]);
             return c;
        }
        int x=mpp[preorder[i]];
        int l=x-a;
        TreeNode* z=new TreeNode(preorder[i]);
        z->left=solve(preorder,i+1,i+l,inorder,a,x-1,mpp);
        z->right=solve(preorder,i+l+1,j,inorder,x+1,b,mpp);
        return z;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return NULL;
        }
        map<int,int> mpp;
        for(int i=0;i<preorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int n=preorder.size()-1;
         TreeNode* root=solve(preorder,0,n,inorder,0,n,mpp);
         return root;
    }
};