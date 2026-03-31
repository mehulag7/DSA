/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* nt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* d=new ListNode(-1);
        ListNode* z=d;
        ListNode* temp=head;
        int count=0;
        ListNode* st=head;
        while(temp){
           count++;
           if(count==k){
            ListNode* j=temp;
            temp=temp->next;
            j->next=NULL;
            ListNode* c=reverse(st);
            d->next=c;
            d=st;
            st=temp;
            count=0;
           }
           else{
            temp=temp->next;
           }
        }
         d->next=st;
        return z->next;
    }
};