class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has only one node
        if (!head || !head->next) return head;
        
        // 1. Split the list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Break the link to separate the halves
        
        // 2. Recursively sort both halves
        left = sortList(left);
        right = sortList(right);
        
        // 3. Merge the sorted halves
        return merge(left, right);
    }

private:
    // Helper function to find the midpoint node of the list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // Offset fast to get the exact left-middle
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Helper function from LeetCode 21 (Merge Two Sorted Lists)
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
