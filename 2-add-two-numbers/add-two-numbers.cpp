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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode*h2=l2;
        int carry=0;
        ListNode* d=new ListNode(-1);
        ListNode* temp=d;
        while(h1 && h2){
            int p=h1->val+h2->val+carry;
            carry=p/10;
            h1->val=p%10;
            temp->next=h1;
            temp=h1;
            h1=h1->next;
            h2=h2->next;
        }
        if(h1){
            while(h1){
               int p=h1->val+carry;
               carry=p/10;
               h1->val=p%10;
            temp->next=h1;
            temp=h1;
            h1=h1->next;
            if(carry==0) break;
            }
        }
        else{
            while(h2){
               int p=h2->val+carry;
               carry=p/10;
               h2->val=p%10;
            temp->next=h2;
            temp=h2;
            h2=h2->next;
            if(carry==0) break;
            }
        }
        if(carry){
            ListNode* j=new ListNode(carry);
            temp->next=j;
        }
        return d->next;
    }
};