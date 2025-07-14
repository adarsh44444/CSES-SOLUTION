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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        ListNode* next;
        while(temp!=nullptr){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
};
// recursive way
//class Solution {
/* public:
    ListNode* reverseList(ListNode* head) {
        // base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // reverse current node's pointer
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
}; */
