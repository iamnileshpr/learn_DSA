class Solution {
public:

    vector<int> nums;

    void inorder(TreeNode* root)
    {
        if(!root)
            return;

        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int left, int right)
    {
        if(left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        inorder(root);

        return build(0, nums.size() - 1);
    }
};