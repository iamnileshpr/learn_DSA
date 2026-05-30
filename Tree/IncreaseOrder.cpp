class Solution {
public:

    TreeNode* prev;

    void inorder(TreeNode* root) {

        if (!root)
            return;

        inorder(root->left);

        // remove left child
        root->left = NULL;

        // connect previous node
        prev->right = root;

        // move prev
        prev = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* dummy = new TreeNode(-1);

        prev = dummy;

        inorder(root);

        return dummy->right;
    }
};