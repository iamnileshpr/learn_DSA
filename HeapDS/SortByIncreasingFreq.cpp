class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : mp){
            pq.push({it.second,-it.first});
            }
        
          while(!pq.empty()){
                int freq=pq.top().first;
                int ele=-pq.top().second;
                pq.pop();
                for(int i=0;i<freq;i++){
                ans.push_back(ele);
                }
          }
        return ans;
    }
};