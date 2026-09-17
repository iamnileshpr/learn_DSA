class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;

        int left = 0;
        int right = 0;

        while (left < nums1.size() && right < nums2.size()) {

            if (nums1[left] < nums2[right]) {
                left++;
            }
            else if (nums1[left] > nums2[right]) {
                right++;
            }
            else {
                // Same element found
                if (res.empty() || res.back() != nums1[left]) {
                    res.push_back(nums1[left]);
                }

                left++;
                right++;
            }
        }

        return res;
    }
};