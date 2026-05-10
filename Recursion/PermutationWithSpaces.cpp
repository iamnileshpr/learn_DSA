class Solution {
  public:
  
    vector<string> ans;

    void solve(string ip, string op) {

        // base case
        if(ip.size() == 0) {
            ans.push_back(op);
            return;
        }

        string op1 = op;
        string op2 = op;

        // with space
        op1.push_back(' ');
        op1.push_back(ip[0]);

        // without space
        op2.push_back(ip[0]);

        // remove first character
        ip.erase(ip.begin());

        solve(ip, op1);
        solve(ip, op2);
    }

    vector<string> permutation(string s) {

        string op = "";

        op.push_back(s[0]);

        s.erase(s.begin());

        solve(s, op);

        return ans;
    }
};