/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:

    vector<Node*> findPreSuc(Node* root, int key) {

        vector<Node*> v = {NULL,NULL};

        Node* x = root;

        while(x){

            if(x->data > key){

                v[1] = x;

                x = x->left;
            }

            else if(x->data < key){

                v[0] = x;

                x = x->right;
            }

            else{

                Node* t = x->left;

                while(t){
                    v[0] = t;
                    t = t->right;
                }

                t = x->right;

                while(t){
                    v[1] = t;
                    t = t->left;
                }

                break;
            }
        }

        return v;
    }
};