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
    void solve(TreeNode* root,int k,int &count,int& p){
        if(count>=k) return;
        if(root==NULL) return;
        solve(root->left,k,count,p);
        count++;
        if(count==k){
            p=root->val;
            return;
        }
        solve(root->right,k,count,p);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int p=-1;
        solve(root,k,count,p);
        return p;
    }
};