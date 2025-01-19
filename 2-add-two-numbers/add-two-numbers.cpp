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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dumb=new ListNode(-1);
        ListNode* ans=dumb;
        int carry=0;
        while(l1!=nullptr||l2!=nullptr){
        int sum=carry;
        if(l1!=nullptr) sum+=l1->val;
        if(l2!=nullptr) sum+=l2->val;
        carry=sum/10;
        sum=sum%10;
        dumb->next=new ListNode(sum);
        dumb=dumb->next;
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;
        }
        if(carry){
            dumb->next=new ListNode(carry);
            dumb=dumb->next;
        }
        return ans->next;
    }
};