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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* head1=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int p=cnt-n;
        temp=head;
        cnt=0;
        while(temp){
            if(cnt==p){
                if(prev!=NULL) {
                    prev->next=temp->next;
                }
                else{
                    head1=head->next;
                }
                temp->next=NULL;
                delete temp;
                break;
            }
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        return head1;
    }
};