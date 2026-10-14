class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n =nums.size(), i;
      int maxi =INT_MIN ,sum =0, start =0;
      int ansStart =-1, ansEnd =-1;
      for(i =0; i<n; i++){
        if(sum == 0){
            start =i;
        }
        sum +=nums[i];
        if(sum > maxi){
            maxi =sum;
            ansStart =start;
            ansEnd =i;
        }
      if(sum < 0){
        sum =0;
      }
      }
      return maxi;
    }
};