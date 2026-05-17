/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
         if(root==NULL) return true;
         else{
             if(root->left==NULL && root->right==NULL) return true;
              bool a=isSumProperty(root->left);
              bool b=isSumProperty(root->right);
              int x=root->right?root->right->data:0;
              int y=root->left?root->left->data:0;
              if(root->data==x+y) return a&b;
              else return false;
         }
    }
};