/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1==NULL){
            ListNode* temp3=headB;
            while(temp2!=NULL) {
                temp3=temp3->next;
                temp2=temp2->next;
            }
            temp1=headA;
             while(temp1!=NULL && temp3!=NULL){
            if(temp1==temp3) return temp1;
            temp1=temp1->next;
            temp3=temp3->next;
        }
        return NULL;
        }
        else{
            ListNode* temp3=headA;
            while(temp1!=NULL) {
                temp3=temp3->next;
                temp1=temp1->next;
            }
            temp2=headB;
             while(temp2!=NULL && temp3!=NULL){
            if(temp2==temp3) return temp2;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        return NULL;
        }
    }
};