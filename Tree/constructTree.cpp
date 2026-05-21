/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<int, int> mp;
    int preorderIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int left,
                    int right)
    {
        // no elements
        if(left > right)
            return NULL;

        // current root from preorder
        int rootValue = preorder[preorderIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // root position in inorder
        int inorderIndex = mp[rootValue];

        // build left subtree
        root->left = build(preorder, inorder,
                           left, inorderIndex - 1);

        // build right subtree
        root->right = build(preorder, inorder,
                            inorderIndex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder)
    {
        // store inorder indexes
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};