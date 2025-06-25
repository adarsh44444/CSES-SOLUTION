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
ListNode* middle(ListNode* head){
    ListNode* fast=head;
    ListNode* slow=head;
    fast=fast->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
ListNode* mergesort(ListNode* l1,ListNode* l2){
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;
    while(l1!=nullptr&&l2!=nullptr){
        if(l1->val<l2->val){
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }
        else{
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
    }
    if(l1) temp->next=l1;
    if(l2) temp->next=l2;
    return dummy->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* mid=middle(head);
        ListNode* right=mid->next;
        mid->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* rightt=sortList(right);
        return mergesort(left,rightt);
    }
};