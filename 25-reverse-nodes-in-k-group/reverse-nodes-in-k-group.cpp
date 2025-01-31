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
        ListNode* temp=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return temp;
    }
    ListNode* findkthnode(ListNode* temp,int k){
        k-=1;
        while(temp!=nullptr&&k!=0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==nullptr){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* newnode=kthnode->next;
            kthnode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=newnode;
        }
        return head;
    }
};