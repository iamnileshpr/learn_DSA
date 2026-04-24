class Solution {
public:
 long long fun(vector<int>&piles,int n,int speed){
            long long h1=0;
            for(int i=0;i<n;i++){
               h1 += ((long long)piles[i] + speed - 1) / speed;
            }
            return h1;
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=0;
        int res = -1;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        while(low<=high){
            int mid=(low+high)/2;
            long long hour=fun(piles,n,mid);
            if(hour>h){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};