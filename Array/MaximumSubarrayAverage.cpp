class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low=0;
        int n=nums.size();
        int high=k-1;
        double sum=0;
        for (int i=0;i<k;i++){
            sum=sum+nums[i];
        }
        double res=sum;
        while(high<n){
            res=max(res, sum);
            low++;
            high++;
            sum=sum-nums[low-1];
            if(high==n) break;
            sum=sum+nums[high];
        }
        return res/k;
    }
};