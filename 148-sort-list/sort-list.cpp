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
ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* d=new ListNode(-1);
        ListNode* temp=d;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        if(left) temp->next=left;
        else temp->next=right;
        return d->next;
    }
    ListNode* ms(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=middleNode(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        left=ms(left);
        right=ms(right);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return ms(head);
    }
};