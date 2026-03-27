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
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt%2){
            cnt=(cnt+1)/2;
        }
        else{
            cnt=cnt/2+1;
        }
        temp=head;
        int a=0;
        while(temp){
            a++;
            if(a==cnt){
                return temp;
            }
            temp=temp->next;
        }
        return temp;
    }
};