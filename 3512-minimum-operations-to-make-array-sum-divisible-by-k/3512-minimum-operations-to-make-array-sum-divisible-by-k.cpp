class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k==0)
        return ans;
        else{
            for(int i=0;i<nums.size();i++){
            while(sum%k!=0 && sum>=0 && nums[i]>=0){
                nums[i]=nums[i]-1;
                sum=sum-1;
                ans++;
            }
        }
        return ans;   
        }
    }
};