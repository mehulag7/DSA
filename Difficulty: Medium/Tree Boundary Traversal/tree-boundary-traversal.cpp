/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:

    bool isLeaf(Node* root){
        return root->left == NULL && root->right == NULL;
    }

    void lft(Node* root, vector<int>& ans){

        Node* curr = root->left;

        while(curr){

            if(!isLeaf(curr))
                ans.push_back(curr->data);

            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void leaf(Node* root, vector<int>& ans){

        if(root == NULL) return;

        if(isLeaf(root)){

            ans.push_back(root->data);

            return;
        }

        leaf(root->left, ans);

        leaf(root->right, ans);
    }

    void rght(Node* root, vector<int>& ans){

        vector<int> temp;

        Node* curr = root->right;

        while(curr){

            if(!isLeaf(curr))
                temp.push_back(curr->data);

            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        reverse(temp.begin(), temp.end());

        for(auto x : temp)
            ans.push_back(x);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if(root == NULL) return ans;

        if(!isLeaf(root))
            ans.push_back(root->data);

        lft(root, ans);

        leaf(root, ans);

        rght(root, ans);

        return ans;
    }
};