// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        map<int,int> mpp;
        Node* temp=head;
        int i=1;
        while(temp){
            mpp[temp->data]=i;
            i++;
            temp=temp->next;
        }
        vector<pair<int,int>> v;
        temp=head;
        i=1;
        while(temp){
            if(mpp[target-temp->data]>i) v.push_back({temp->data,target-temp->data});
            i++;
            temp=temp->next;
        }
        return v;
    }
};