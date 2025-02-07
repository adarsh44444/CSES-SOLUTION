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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap: smallest value comes first
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a priority queue (min-heap) with the custom comparator
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push the head of each list into the priority queue
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode* root = new ListNode(0); // Dummy head for the merged list
        ListNode* tail = root;

        // Extract the smallest node and add it to the result list
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;

            // If the extracted node has a next, push it into the queue
            if (temp->next) {
                pq.push(temp->next);
            }
        }

        return root->next; // Return the merged list, excluding the dummy head
    }
};
