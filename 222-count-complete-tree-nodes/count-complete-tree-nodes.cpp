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
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
           int a=q.size();
           for(int i=0;i<a;i++){
            TreeNode* x=q.front();
            ans++;
            q.pop();
            if(x->left){
                //mpp[x->left]=x;
                q.push(x->left);
            }
            if(x->right){
               // mpp[x->right]=x;
                q.push(x->right);
            }
           }
        }
        return ans;
    }
};