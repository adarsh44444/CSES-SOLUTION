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
        if(head==nullptr||head->next==nullptr) return head;
        int length=0;
        ListNode* temp1=head;
        while(temp1!=nullptr){
            temp1=temp1->next;
            length++;
        }
        k=k%length;
        if(k==0) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        int cnt=1;
        while(cnt<=k){
            fast=fast->next;
            cnt++;
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp;
        temp=slow->next;
        slow->next=nullptr;
        fast->next=head;
        return temp;
    }
};