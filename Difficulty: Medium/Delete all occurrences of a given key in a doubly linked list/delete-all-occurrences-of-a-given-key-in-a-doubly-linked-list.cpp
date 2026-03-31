/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        struct Node* d=*head_ref;
        while(d){
            if(d->data==x){
                if(d==*head_ref){
                    *head_ref=d->next;
                }
                if(d->next==NULL){
                    if(d->prev!=NULL) d->prev->next=NULL;
                    d->prev=NULL;
                    d=d->next;
                }
                else{
                    d->next->prev=d->prev;
                  if(d->prev!=NULL)  d->prev->next=d->next;
                  d=d->next;
                }
            }
           else d=d->next;
        }
        return;
    }
};