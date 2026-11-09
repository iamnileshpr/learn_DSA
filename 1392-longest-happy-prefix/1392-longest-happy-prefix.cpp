class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int i = 1, len = 0;

        vector<int> lps(n, 0);

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        string ans = s.substr(0, lps[n - 1]);

        return ans;
    }
};