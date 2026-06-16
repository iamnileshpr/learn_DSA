class Solution {
public:

    void dfs(TreeNode* root,
             int target,
             vector<int>& path,
             vector<vector<int>>& ans)
    {
        if(root == NULL)
            return;

        path.push_back(root->val);

        // leaf node
        if(root->left == NULL &&
           root->right == NULL)
        {
            if(target == root->val)
            {
                ans.push_back(path);
            }
        }

        dfs(root->left,
            target-root->val,
            path,
            ans);

        dfs(root->right,
            target-root->val,
            path,
            ans);

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(
        TreeNode* root,
        int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root,targetSum,path,ans);

        return ans;
    }
};