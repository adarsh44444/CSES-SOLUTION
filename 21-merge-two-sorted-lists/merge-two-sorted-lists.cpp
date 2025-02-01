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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1!=nullptr&&t2!=nullptr){
            if(t1->val<t2->val){
                temp->next=t1;
                temp=temp->next;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=temp->next;
                t2=t2->next;
            }

        }
        while(t1!=nullptr){
            temp->next=t1;
            temp=temp->next;
            t1=t1->next;
        }
        while(t2!=nullptr){
            temp->next=t2;
            temp=temp->next;
            t2=t2->next;
        }
        return dummy->next;
    }
};