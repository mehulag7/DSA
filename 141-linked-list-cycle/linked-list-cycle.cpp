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
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        while(temp){
            if(temp->val==1e6) return true;
            temp->val=1e6;
            temp=temp->next;
        }
        return false;
    }
};