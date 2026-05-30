class Solution {
public:

    ListNode* findMiddle(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
            prev->next = NULL;

        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        if (!head)
            return NULL;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* mid = findMiddle(head);

        TreeNode* root = new TreeNode(mid->val);

        root->left = sortedListToBST(head);

        root->right = sortedListToBST(mid->next);

        return root;
    }
};