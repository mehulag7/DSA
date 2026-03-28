/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        int pos=-1;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) {
               pos=0;
               break;
            }
        }
        if(pos==-1) return 0;
        else{
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            pos=1;
            slow=slow->next;
            while(slow!=fast){
                pos++;
                slow=slow->next;
            }
            return pos;
        }
    }
};