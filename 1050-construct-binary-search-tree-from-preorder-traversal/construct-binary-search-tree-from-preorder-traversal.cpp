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
    TreeNode* build(int& i,int A,vector<int>&preorder){
        if(i==preorder.size() || preorder[i]>=A) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=build(i,root->val,preorder);
        root->right=build(i,A,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(i,INT_MAX,preorder);
    }
};