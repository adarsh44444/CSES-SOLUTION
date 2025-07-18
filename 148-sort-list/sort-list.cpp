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
    ListNode* slow=head;
    ListNode* fast=head;
    fast=fast->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* t1,ListNode* t2){
    ListNode* dummy=new ListNode(-1);
    ListNode* dummyhead=dummy;
    while(t1!=nullptr&&t2!=nullptr){
        if(t1->val<t2->val){
            dummy->next=t1;
            dummy=dummy->next;
            t1=t1->next;
        }
        else{
            dummy->next=t2;
            dummy=dummy->next;
            t2=t2->next;
        }
    }
    if(t1) dummy->next=t1;
    if(t2) dummy->next=t2;
    return dummyhead->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *t1=middle(head);
        ListNode* t2=t1->next;
        t1->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* right=sortList(t2);
        return merge(left,right);
    }
};