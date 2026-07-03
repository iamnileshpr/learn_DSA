class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int buy, vector<int>& prices) {
        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
            int buyStock = -prices[i] + solve(i + 1, 0, prices);
            int skip = solve(i + 1, 1, prices);

            return dp[i][buy] = max(buyStock, skip);
        }
        else {
            int sellStock = prices[i] + solve(i + 1, 1, prices);
            int hold = solve(i + 1, 0, prices);

            return dp[i][buy] = max(sellStock, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));

        return solve(0, 1, prices);
    }
};