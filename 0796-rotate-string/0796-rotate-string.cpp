class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string sum=s+s;

        return sum.find(goal)!=string::npos;
    }
};