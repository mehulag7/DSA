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

    int ans;

    vector<int> solve(TreeNode* root){

        if(!root){
            return {1,INT_MAX,INT_MIN,0};
        }

        vector<int> l = solve(root->left);

        vector<int> r = solve(root->right);

        if(l[0] && r[0] && root->val > l[2] && root->val < r[1]){

            int sum = l[3] + r[3] + root->val;

            ans = max(ans,sum);

            int mn = min(root->val,l[1]);

            int mx = max(root->val,r[2]);

            return {1,mn,mx,sum};
        }

        return {0,0,0,0};
    }

    int maxSumBST(TreeNode* root) {

        ans = 0;

        solve(root);

        return ans;
    }
};