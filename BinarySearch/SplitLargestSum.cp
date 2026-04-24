class Solution {
public:

    bool canSplit(vector<int>& nums, int k, int maxSum){
        
        int count = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            
            if(sum + nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for(int x : nums)
            high += x;

        int res = high;

        while(low <= high){
            
            int mid = low + (high - low)/2;

            if(canSplit(nums, k, mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};