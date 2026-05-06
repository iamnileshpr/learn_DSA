class Solution {
  public:
  
    // helper recursion
    void solve(string &s, int i, char c) {
        if(i == s.size()) return;

        if(s[i] == c) {
            s.erase(i, 1);
            solve(s, i, c);   // stay at same index
        } else {
            solve(s, i + 1, c);
        }
    }

    // function called by driver
    void removeCharacter(string &s, char c) {
        solve(s, 0, c);
    }
};