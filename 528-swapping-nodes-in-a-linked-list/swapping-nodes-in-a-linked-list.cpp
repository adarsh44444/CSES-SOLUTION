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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* rightptr=head;
       ListNode* leftptr=head;
       for(int i=0;i<k-1;i++){
        rightptr=rightptr->next;
       }
       ListNode* endptr=rightptr;
       while(rightptr->next){
        rightptr=rightptr->next;
        leftptr=leftptr->next;
       }
       swap(endptr->val,leftptr->val);
       return head; 
    }
};