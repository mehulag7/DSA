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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* temp=head;
        ListNode* tail=NULL;
        int count=0;
        while(temp){
            count++;
            tail=temp;
            temp=temp->next;
        }
        cout<<count<<endl;
        if(k%count==0) return head;
        k=k%count;
        k=count-k+1;
        temp=head;
        ListNode* prev=NULL;
        while(temp){
            k--;
            if(k==0){
                prev->next=NULL;
                tail->next=head;
                return temp;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};