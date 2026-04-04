/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    struct cmp {
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

Node* flatten(Node* root) {

    if(!root) return NULL;

    Node* dummy = new Node(-1);
    Node* curr = dummy;

    priority_queue<Node*, vector<Node*>, cmp> pq;

    pq.push(root);

    while(!pq.empty()){

        Node* node = pq.top();
        pq.pop();

        curr->bottom = node;
        curr = node;

        if(node->bottom) pq.push(node->bottom);
        if(node->next) pq.push(node->next);

        node->next = NULL;
    }

    return dummy->bottom;
}
};