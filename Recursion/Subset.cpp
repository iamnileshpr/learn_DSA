class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        // base case
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // include
        curr.push_back(nums[i]);
        solve(i + 1, nums, curr, ans);

        // backtrack
        curr.pop_back();

        // exclude
        solve(i + 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans);
        return ans;
    }
};