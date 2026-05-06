class Solution {
  public:
    int sumOfDigits(int n) {
        // code here
        if(n==0)
        return 0;
        int d=n%10;
        int m=n/10;
        int ans =sumOfDigits(m);
        return d+ans;
    }
};