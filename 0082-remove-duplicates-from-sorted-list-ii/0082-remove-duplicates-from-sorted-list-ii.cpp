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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // Dummy node handles cases where the original head is removed
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // Check if current node is the start of duplicates
            if (curr->next && curr->val == curr->next->val) {
                // Skip all nodes with the same value
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Bypass the entire duplicate block
                prev->next = curr->next;
            } else {
                // Current node is unique; advance prev
                prev = prev->next;
            }
            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Prevent memory leak
        return result;
    }
};