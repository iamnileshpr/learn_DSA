class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        vector<int>ps(n,0);
        ps[0]=nums[0];

        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        } 
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(ps[i]==k) count++;

            int val=ps[i]-k;
            if(m.find(val)!=m.end()){
                count = count + m[val];
            }
            if(m.find(val)==m.end()){
               m[ps[i]]=0;
            }
            m[ps[i]]++;
        }
        return count;
    }
};