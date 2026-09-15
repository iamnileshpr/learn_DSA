class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x: nums){
            mp[x]++;
        }
        vector<int>res;
        for(auto const& [num,count]:mp){
            if(count==1)
            res.push_back(num);
        }
        return res;
    }
};