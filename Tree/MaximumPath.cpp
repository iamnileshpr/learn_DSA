/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxSum;
int solve(TreeNode* root){
    if(root==NULL) return 0;

    int lh=solve(root->left);
    int rh=solve(root->right);

    int neeche_ans_milgaya=lh+rh+root->val;

    int koi_ek_accha_hai=max(lh,rh)+root->val;

    int yahi_node_accha_hai=root->val;;

    maxSum=max({maxSum,neeche_ans_milgaya,koi_ek_accha_hai,yahi_node_accha_hai});

    return max(koi_ek_accha_hai,yahi_node_accha_hai);
}
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};