class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int city, vector<bool>& vis) {
        vis[city] = true;

        for (int next = 0; next < isConnected.size(); next++) {
            if (isConnected[city][next] == 1 && !vis[next]) {
                dfs(isConnected, next, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, i, vis);
                provinces++;
            }
        }

        return provinces;
    }
};