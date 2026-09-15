#include <vector>

class NumArray {
private:
    // This will hold our running totals (Prefix Sums)
    std::vector<int> running_total;

public:
    // 1. CONSTRUCTOR: This runs ONCE at the start to build the running totals
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        
        // Size is n + 1 so we can start with a baseline of 0 at index 0
        running_total.resize(n + 1, 0); 
        
        // Calculate the running totals
        for (int i = 0; i < n; i++) {
            running_total[i + 1] = running_total[i] + nums[i];
        }
    }
    
    // 2. QUERY FUNCTION: This runs instantly every time you ask for a range
    int sumRange(int left, int right) {
        // To find the sum between left and right:
        // Take the total up to 'right' and subtract everything before 'left'
        return running_total[right + 1] - running_total[left];
    }
};
