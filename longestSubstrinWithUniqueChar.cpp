class Solution {
public:
    int find(vector<int> &a)
{
   int maxc=-1;
   for(int i=0;i<256;i++)
   maxc=max(maxc,a[i]);
   return maxc;
}

    int characterReplacement(string s, int k) {
        int low=0;
        int high=0;
        int res=INT_MIN;
        int n=s.size();
        vector<int>f(256,0);
        for(int high=0;high<n;high++){
            f[s[high]]++;
            int max_cnt=find(f);
            int len = high-low+1;
            int diff=len-max_cnt;
            while(diff>k){
                f[s[low]]--;
                low++;
                int max_cnt=find(f);
                int len = high-low+1;
                int diff=len-max_cnt;
            }
             len = high-low+1;
             int res=max(res,len);
        }
        return res;
    }
};

