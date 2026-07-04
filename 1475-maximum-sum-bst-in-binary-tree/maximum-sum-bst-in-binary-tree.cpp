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

class NodeValue {
    public:
    int minNode, maxNode, sum;
    NodeValue(int mini, int maxi, int s) {
        minNode =mini;
        maxNode =maxi;
        sum =s;
    }
};


class Solution {
public:

    int ans =0;
    NodeValue helper(TreeNode* root) {
        if(!root) {
            return NodeValue(INT_MAX, INT_MIN,0);
        }
        auto left =helper(root->left);
        auto right =helper(root->right);

        if(left.maxNode<root->val && root->val < right.minNode) {
            int curr =left.sum+right.sum+root->val;
            ans =max(ans, curr);

            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), curr);
        }
        return NodeValue(INT_MIN, INT_MAX, 0);
    }



    int maxSumBST(TreeNode* root) {
        //tc - o(n), sc - o(1)
        helper(root);
        return ans;
    }
};