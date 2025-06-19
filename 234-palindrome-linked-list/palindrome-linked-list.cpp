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
ListNode* reverse(ListNode* head){
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* res=reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return res;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* temp=reverse(slow->next);
        while(temp!=nullptr){
            if(temp->val!=head->val) return 0;
            else{
                temp=temp->next;
                head=head->next;
            }
        }
        return 1;
    }
};