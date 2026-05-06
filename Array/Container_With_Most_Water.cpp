class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
         int area=0;
        while(left<=right){
            int diff=min(height[left],height[right]);
            int width=right-left;
            int max_area=width*diff;
            if(max_area>area) area=max_area;
            if(height[left]<height[right]){ left++;}
            else right--;
        }
        return area;
    }
};