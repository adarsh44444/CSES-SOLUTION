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
       int length=1;
       ListNode* temp=head;
       while(temp->next!=nullptr){
        length++;
        temp=temp->next;
       }
       temp->next=head;
       k=k%length;
       int upto=length-k-1;
       ListNode* temp1=head;
       for(int i=0;i<upto;i++){
        temp1=temp1->next;
       }
       head=temp1->next;
       temp1->next=nullptr;
        return head;
        
    }
};