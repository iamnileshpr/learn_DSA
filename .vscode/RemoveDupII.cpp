class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int,int> freq;
        unordered_map<int,int> first;
        unordered_map<int,int> last;

        int n = nums.size();

        // Step 1: Fill maps
        for(int i = 0; i < n; i++){
            int x = nums[i];

            freq[x]++;

            if(first.find(x) == first.end()){
                first[x] = i;
            }

            last[x] = i;
        }

        // Step 2: Find degree
        int degree = 0;
        for(auto it : freq){
            degree = max(degree, it.second);
        }

        // Step 3: Find minimum length
        int ans = INT_MAX;

        for(auto it : freq){
            if(it.second == degree){
                int x = it.first;
                int len = last[x] - first[x] + 1;
                ans = min(ans, len);
            }
        }

        return ans;
    }
};