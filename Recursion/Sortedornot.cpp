class Solution {
public:
bool check(vector<int>&nums,int i){
    if(i==nums.size()-1 || i==nums.size()) return true;
    if(nums[i]>nums[i+1]) return false;
    return check(nums,i+1);
}
    bool dec(vector<int>& nums, int i) {
        if (i >= nums.size() - 1) return true;
        if (nums[i] < nums[i + 1]) return false;
        return dec(nums, i + 1);
    }

    bool isMonotonic(vector<int>& nums) {
        return check(nums,0)||dec(nums,0);
    }
};