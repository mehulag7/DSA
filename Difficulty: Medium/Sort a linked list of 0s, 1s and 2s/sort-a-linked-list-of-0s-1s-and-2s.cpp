/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* d1=new Node(-1);
        Node* d2=new Node(-1);
        Node* d3=new Node(-1);
        Node* temp=head;
        Node* temp1=d1;
        Node* temp2=d2;
        Node* temp3=d3;
        while(temp){
            if(temp->data==0){
                d1->next=temp;
                d1=temp;
            }
            else if(temp->data==1){
                d2->next=temp;
                d2=temp;
            }
            else{
                 d3->next=temp;
                d3=temp;  
            }
            temp=temp->next;
        }
       d1->next=temp2->next;
       d3->next=NULL;
       if(temp2->next==NULL){
           d1->next=temp3->next;
       }
       else{
           d2->next=temp3->next;
       }
       return temp1->next;
    }
};