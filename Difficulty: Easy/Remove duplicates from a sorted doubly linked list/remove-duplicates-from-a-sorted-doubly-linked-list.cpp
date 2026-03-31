/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        struct Node* pre=head;
        struct Node* curr=head->next;
        while(curr){
            if(pre->data==curr->data){
                if(pre==head){
                    head=head->next;
                }
                if(pre->prev) {
                    pre->prev->next=curr;
                    curr->prev=pre->prev;
                }
                else curr->prev=NULL;
                pre=curr;
                curr=curr->next;
            }
            else{
                pre=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};