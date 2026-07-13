class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        root->left = nullptr;
        root->right = leftSubtree;

        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }

        curr->right = rightSubtree;
    }
};