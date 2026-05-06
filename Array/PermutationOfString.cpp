class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if (n > m) return false;
        vector<int>f1(26,0),f2(26,0);
        for(int i=0;i<n;i++){
            f1[s1[i]-'a']++;
        }
        int low=0;
        int high=0;
        while(high<m){
             f2[s2[high]-'a']++;
            if(high-low+1>n){
                 f2[s2[low]-'a']--;
                low++;
            }
            if(high-low+1 ==n){
                bool same = true;
            for (int j = 0; j < 26; j++) {
                if (f1[j] != f2[j]) {
                    same = false;
                    break;
                }
            }
            if (same) return true;
        }
         high++;
    }
    return false;

}
};