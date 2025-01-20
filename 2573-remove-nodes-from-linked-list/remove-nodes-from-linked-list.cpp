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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int> arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxi){
                maxi=arr[i];
            }
            else{
                arr[i]=-1;
            }
        }
        ListNode* dumb=new ListNode(-1);
        ListNode* ans=dumb;
        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                dumb->next=new ListNode(arr[i]);
                dumb=dumb->next;
            }
        }
        return ans->next;
    }
};