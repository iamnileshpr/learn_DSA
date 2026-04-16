class Solution {
  public:
  
  bool isvalid(vector<int>&arr,int k,int max){
      int student=1;
      int sum=0;
      
      for(int x : arr){
          sum += x;
          
          if(sum > max){
              student++;
              sum = x;
          }
          
          if(student > k) return false;
      }
      
      return true;
  }

  int findPages(vector<int> &arr, int k) {
      
      // Important edge case
      if(k > arr.size()) return -1;
      
      int start = *max_element(arr.begin(), arr.end());
      int end = 0;
      
      for(int x : arr){
          end += x;
      }
      
      int res = -1;
      
      while(start <= end){
          
          int mid = (start + end)/2;
          
          if(isvalid(arr, k, mid)){
              res = mid;
              end = mid - 1;
          }
          else{
              start = mid + 1;
          }
      }
      
      return res;
  }
};